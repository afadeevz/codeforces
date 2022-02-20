#!/usr/bin/env python3.10

import argparse
import json
import os
from pathlib import Path
import pathlib
import shutil
import subprocess

def set_workdir():
    os.chdir(os.path.dirname(os.path.abspath(__file__)))

def make_default_config():
    return {
        'last_solved': None
    }

def load_config(path='./cf.json'):
    file_path = Path(path)
    if not file_path.is_file():
        print('Config file does not exist, using default values')
        return make_default_config()

    with open(path, 'r') as file:
        return json.load(file)

def save_config(config, args, path='./cf.json'):
    config['last_solved'] = args.task_id
    with open(path, 'w', encoding='utf-8') as file:
        return json.dump(config, file, ensure_ascii=False, indent=4)

def build_args_parser(config):
    parser = argparse.ArgumentParser()
    subparsers = parser.add_subparsers(dest='subcommand')
    solve_parser = subparsers.add_parser('solve')
    solve_parser.add_argument('-t', type=str, default=config['last_solved'], dest='task_id')
    test_parser = subparsers.add_parser('test')
    test_parser.add_argument('-t', type=str, default=config['last_solved'], dest='task_id')
    return parser

def parse_task_id(task_id):
    pos = 0
    while pos < len(task_id) and task_id[pos].isdigit():
        pos += 1

    if pos >= len(task_id):
        raise ValueError(f'Invalid task ID {task_id}')

    return task_id[0 : pos], task_id[pos:]

def gen_solution_path(contest, task_letter):
    hundreds = int(contest) // 100
    dirA = str(hundreds).zfill(2) + 'XX'

    dirB = contest
    fileName = contest + task_letter + '.cpp'

    return Path.cwd().joinpath('solutions').joinpath(dirA).joinpath(dirB).joinpath(fileName)

def try_create_file(path):
    pathlib.Path(path.parent).mkdir(parents=True, exist_ok=True)

    if path.is_file():
        return
    
    templatePath = Path('./template.cpp')
    shutil.copy(templatePath, path)

def open_file_in_ide(path):
    subprocess.check_call(['code', '-r', path])

def solve(args):
    if args.task_id is None:
        raise ValueError('Task ID was not specified')

    contest, task_letter = parse_task_id(args.task_id)
    path = gen_solution_path(contest, task_letter)
    try_create_file(path)
    open_file_in_ide(path)

def compile_solution(src_path, output_path):
    print('Compiling...')
    subprocess.check_call(['g++', '-Os', '-std=gnu++2a', src_path, '-o', output_path])

def get_words(file_path):
    with open(file_path) as file:
        for line in file:
            for word in line.split():
                yield word

def run_solution(solution_path, input_path, output_path):
    with open(input_path) as fin:
        with open(output_path, 'w') as fout:               
            subprocess.run([solution_path], stdin=fin, stdout=fout, timeout=2)

def check_answer(output_path, answer_path):
    output_words = get_words(output_path)
    answer_words = get_words(answer_path)
    idx = 1
    for idx, out, ans in zip(range(1, 2**20), output_words, answer_words):
        if out != ans:
            print(f'Wrong answer at token {idx}: expected {ans}, got {out}')
            print("FAILED")
            return
    for ans in answer_words:
        print(f'Wrong answer at token {idx}: expected {ans}, got EOF')
        print("FAILED")
        return
    print("PASSED")

def test_solution(solution_path):
    print('Testing...')

    solution_path = 'tmp/solution'
    input_txt = 'input.txt'
    output_txt = 'tmp/output.txt'
    answer_txt = 'answer.txt'

    run_solution(solution_path, input_txt, output_txt)
    check_answer(output_txt, answer_txt)

def test(args):
    if args.task_id is None:
        raise ValueError('Task ID was not specified')

    contest, task_letter = parse_task_id(args.task_id)
    path = gen_solution_path(contest, task_letter)
    output_path = 'tmp/solution'
    Path('tmp').mkdir(exist_ok=True)
    compile_solution(path, output_path)
    test_solution(output_path)

def handle_args(args):
    print(args)
    match args.subcommand:
        case 'solve':
            solve(args)
        case 'test':
            test(args)
        case _:
            raise ValueError(f'Invalid subcommand {args.subcommand}')

def main():
    try:
        set_workdir()
        config = load_config()
        parser = build_args_parser(config)
        args = parser.parse_args()
        handle_args(args)
        save_config(config, args)
    except subprocess.TimeoutExpired:
        print("Time limit exceeded (2s)")

if __name__ == '__main__':
    main()