/**
 * CS50 Pset 3
 * helpers.c
 *
 * Author: Jeffrey Chiu
 * Helper functions to have computer read music
 *
**/

// Helper functions for music

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "helpers.h"
#include <stdlib.h>
#include <math.h>

// Converts a fraction formatted as X/Y to eighths
//Just find the gcf between the denominator and 8 and multiply that by numeratir
int duration(string fraction)
{
    // TODO
    int Y = atoi(&fraction[2]);
    int X = atoi(&fraction[0]);
    int multiplier = 8 / Y;
    if (multiplier > 1)
    {
        return X * multiplier;
    }

    return X;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
    //octave is always 2nd to last char
    char octave = note[strlen(note) - 1];
    //set A4 = 0
    int semitone = 0;
    //This is the letter
    char pitch = note[0];
    //Only b or # are counted, everything else is ovewr
    char accidental = note[1];


    if (pitch == 'A')
    {
        semitone += 0;
    }
    else if (pitch == 'B')
    {
        semitone += 2;
    }
    else if (pitch == 'C')
    {
        semitone -= 9;
    }
    else if (pitch == 'D')
    {
        semitone -= 7;
    }
    else if (pitch == 'E')
    {
        semitone -= 5;
    }
    else if (pitch == 'F')
    {
        semitone -= 4;
    }
    else if (pitch == 'G')
    {
        semitone -= 2;
    }

    if (accidental == '#')
    {
        semitone++;
    }

    else if (accidental == 'b')
    {
        semitone--;
    }
    semitone += (octave - '4') * 12;
    double expo = (double) semitone / 12;
    int result = round(pow(2.0, expo) * 440);
    return result;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
    if (strcmp(s, "\n") ==  0 || strcmp(s, "\r")  == 0 || strcmp(s, "\r\n") == 0 || strcmp(s, "") == 0)
    {
        return true;
    }
    return false;
}