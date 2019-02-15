"""
 * CS50 Pset 6
 * hello.py
 *
 * Author: Jeffrey Chiu
 * Basic Hello World Program in Python
 *
"""
from cs50 import get_string

# get user name
name = get_string("What is your name?\n")
print("hello, " + name)