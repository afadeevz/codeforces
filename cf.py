#!/usr/bin/env python3.10

import argparse
from base64 import decode
from email.policy import default
import json
import os
from pathlib import Path
import pathlib
import shutil

def set_workdir():
    os.chdir(os.path.dirname(os.path.abspath(__file__)))

def make_default_config():
    return {
        "last_solved": None
    }

def load_config(path='./cf.json'):
    filePath = Path(path)
    if not filePath.is_file():
        print("Config file does not exist, using default values")
        return make_default_config()

    with open(path, 'r') as file:
        return json.load(file)

def save_config(config, path='./cf.json'):
    with open(path, 'w', encoding='utf-8') as file:
        return json.dump(config, file, ensure_ascii=False, indent=4)

def build_args_parser(config):
    parser = argparse.ArgumentParser()
    subparsers = parser.add_subparsers(dest='subcommand')
    solve_parser = subparsers.add_parser('solve')
    solve_parser.add_argument('-t', type=str, default=config['last_solved'], dest="task_id")
    return parser

def parse_task_id(task_id):
    pos = 0
    while pos < len(task_id) and task_id[pos].isdigit():
        pos += 1

    if pos >= len(task_id):
        raise ValueError(f'Invalid task ID {task_id}')

    return task_id[0 : pos], task_id[pos]

def gen_solution_path(contest, taskLetter):
    hundreds = int(contest) // 100
    dirA = str(hundreds).zfill(2) + 'XX'

    dirB = contest
    fileName = contest + taskLetter + '.cpp'

    return Path.cwd().joinpath('solutions').joinpath(dirA).joinpath(dirB).joinpath(fileName)

def try_create_file(contest, taskLetter):
    path = gen_solution_path(contest, taskLetter)
    pathlib.Path(path.parent).mkdir(parents=True, exist_ok=True)

    if path.is_file():
        return
    
    templatePath = Path('./template.cpp')
    shutil.copy(templatePath, path)

def solve(args):
    if args.task_id is None:
        raise ValueError("Task ID was not specified")

    contest, taskLetter = parse_task_id(args.task_id)
    
    try_create_file(contest, taskLetter)

def handle_args(args):
    print(args)
    match args.subcommand:
        case 'solve':
            solve(args)
        case _:
            raise ValueError(f'Invalid subcommand {args.subcommand}')


def main():
    set_workdir()
    config = load_config()
    parser = build_args_parser(config)
    args = parser.parse_args()
    handle_args(args)
    save_config(config)

if __name__ == '__main__':
    main()