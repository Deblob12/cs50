"""
 * CS50 Pset 6
 * cash.py
 *
 * Author: Jeffrey Chiu
 * Greedy algorithm to determine minimum amount of coins needed to return the amount owed
 *
"""
from cs50 import get_float


def main():
    # ensures input is nonnegative
    while (True):
        owed = get_float("Change owed: ")
        if (owed >= 0):
            break

    # convert input into int to avoid floating point errors
    owed = int(owed * 100)

    # counter variable to count how many coins are needed
    counter = 0
    # number of quarters
    counter += owed // 25
    owed %= 25
    # number of dimes
    counter += owed // 10
    owed %= 10
    # number of nickels
    counter += owed // 5
    owed %= 5
    # number of pennies
    counter += owed
    print(counter)


if __name__ == '__main__':
    main()