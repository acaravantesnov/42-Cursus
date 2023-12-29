#!/usr/bin/env python
import sys
def main():
    # Read from standard input
    input_data = sys.stdin.read()
    # Print to standard output
    print("Content-Type: text/plain\n")
    print(input_data)
if __name__ == "__main__":
    main()