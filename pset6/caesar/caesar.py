"""
 CS50 Pset 6
 caesar.py

 Author: Jeffrey Chiu
 Performs caesar cipher shift given that the first command line argument is the cipher
"""

import sys
from cs50 import get_string


def main():
    # make sure there are the right number of command line arguments
    if len(sys.argv) != 2:
        print("Usage: ./caesar k")
        sys.exit(1)
    # stores keyword shift
    keyword = sys.argv[1]
    p = get_string("plaintext: ")
    print("ciphertext: ", end="")
    for i in range(len(p)):
        if not (p[i].isalpha()):
            print(p[i], end="")
        else:
            z = str(cipheraddition(p[i], keyword))
            print(z, end="")
    print()


# performs necessary transformations
def cipheraddition(p, k):
    # checks if letter is uppercase
    if (p.isupper()):
        p = chr(ord(p) - ord('A'))
        p = chr((ord(p) + int(k)) % 26 + ord('A'))
        return p

    # checks if letter is lowercase
    else:
        p = chr(ord(p) - ord('a'))
        p = chr((ord(p) + int(k)) % 26 + ord('a'))
        return p


# calls main function
if __name__ == '__main__':
    main()