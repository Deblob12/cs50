"""
 * CS50 Pset 6
 * mario.py
 *
 * Author: Jeffrey Chiu
 * mario/more from pset1 in python
 *
"""

from cs50 import get_int

# Function to ensure entered height is within [0, 23]
while(True):
    height = get_int("Height: ")
    if height > 0 and height <= 23:
        break

for i in range(height):
    # print proper starting spaces
    for j in range(height - i - 1, 0, -1):
        print(" ", end="")

    # print proper number of hashtags on left side
    for l in range(i + 1):
        print("#", end="")

    # print spaces in between
    print("  ", end="")

    # print hashtags on right side
    for m in range(i + 1):
        print("#", end="")

    # new line!
    print()
