/**
 * CS50 Pset 2
 * caesar.c
 *
 * Author: Jeffrey Chiu
 * Performs caesar cipher shift given that the first command line argument is the cipher
 *
**/




#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char cipheraddition(char p, int k);

int main(int argc, string argv[])
{
    //Makes sure the user enters the right amount of command line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    //store the cipher key
    int keyword = atoi(argv[1]);


    //get the message to be encrypted
    string p = get_string("plaintext: ");

    printf("ciphertext: ");

    //loop through and apply vigenere cipher and print out the encrypted message
    for (int i = 0, length = strlen(p); i < length; i++)
    {
        //if message part is not alphabetic just simply print it and continue to next cycle
        if (!isalpha(p[i]))
        {
            printf("%c", p[i]);
            continue;
        }
        else
        {
            //perform cipher shift
            char z = cipheraddition(p[i], keyword);
            printf("%c", z);
        }
    }
    printf("\n");
    return 0;
}

//performs the required cipher shift
char cipheraddition(char p, int k)
{
    if (isupper(p))
    {
        p = p - 'A';
        p = (p + k) % 26 + 'A';
        return p;
    }
    else
    {
        p = p - 'a';
        p = (p + k) % 26 + 'a';
        return p;
    }
}