"""
 CS50 Pset 6
 bleep.py

 Author: Jeffrey Chiu
 Performs censoring of banned words given input banned words file
"""


from cs50 import get_string
from sys import argv, exit


def main():

    # TODO
    # censor holds all banned words
    censor = set()
    # if the amount of cmd arguments is not 2, return error message
    if len(argv) != 2:
        print("Usage: python bleep.py dictionary")
        exit(1)
    # adds banned words to set
    with open(argv[1], "r") as f:
        for line in f:
            censor.add(line.strip())
    # gets user message
    msg = get_string("What message would you like to censor?\n")
    words = msg.split(" ")
    # provides modified output
    for j in range(len(words)):
        if words[j].lower() in censor:
            for i in range(len(words[j])):
                print("*", end="")
        else:
            print(words[j], end="")
        if (j == len(words) - 1):
            print()
        else:
            print(" ", end="")


if __name__ == "__main__":
    main()
