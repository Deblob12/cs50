/**
 * CS50 Pset 2
 * crack.c
 *
 * Author: Jeffrey Chiu
 * Cracks passwords based on C’s DES-based crypt function
 *
**/

#define _XOPEN_SOURCE
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <crypt.h>
#include <unistd.h>

int main(int argc, string argv[])
{
    //if there is not 2 and only 2 command line arguments, exit!
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    //all possible characters in the password
    string possible = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    //store the crypted hash
    string hash = argv[1];
    int length = strlen(hash);

    //obtain the salt from the hash
    char salt[3] = {hash[0], hash[1], '\0'};
    const int possiblelength = 57;

    //create the possible password, maximum 5 characters with sixth being \0
    char cipher[6];
    cipher[5] = '\0';

    //loop through each index one at a time and add a potential charactar, then check to see if it matches the hash
    for (int i = 0; i < possiblelength; i++)
    {
        for (int j = 0; j < possiblelength; j++)
        {
            for (int k = 0; k < possiblelength; k++)
            {
                for (int l = 0; l < possiblelength; l++)
                {
                    for (int m = 0; m < possiblelength; m++)
                    {
                        cipher[0] = possible[i];
                        cipher[1] = possible[j];
                        cipher[2] = possible[k];
                        cipher[3] = possible[l];
                        cipher[4] = possible[m];

                        if (strcmp(crypt(cipher, salt), hash) == 0)
                        {
                            printf("%s\n", cipher);
                            return 0;
                        }
                    }
                }
            }
        }
    }

    //password cannot be cracked
    printf("Crack.c is defeated\n");
    return 1;
}