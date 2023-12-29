#!/usr/bin/python3
import sys
import os

def main():
	# print all env variables
	print("HOLA")
	print(os.environ)
	2 / 0

	# Check if there are command-line arguments
	if len(sys.argv) == 1:
		print("Usage: python script.py [arg1] [arg2] ...")
	else:
		# Print each command-line argument
		print("Arguments:")
		for i, arg in enumerate(sys.argv[1:], start=1):
			print(f"Argument {i}: {arg}")

if __name__ == "__main__":
    main()
