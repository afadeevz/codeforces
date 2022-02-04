import argparse

def main():
    parser = argparse.ArgumentParser()
    subparsers = parser.add_subparsers()
    solve_parser = subparsers.add_parser("solve")
    

if __name__ == '__main__':
    main()