/**
 * CS50 Pset 2
 * vigenere.c
 *
 * Author: Jeffrey Chiu
 * Performs vigenere cipher shift given that the first command line argument is the cipher
 *
**/




#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char cipheraddition(char p, char k);

int main(int argc, string argv[])
{
    //Makes sure the user enters the right amount of command line argument
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }

    //store the cipher key
    string keyword = argv[1];

    // Makes sure the cipher key is completely alphabetic
    for (int i = 0, length = strlen(keyword); i < length; i++)
    {
        if (!isalpha(keyword[i]))
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
        else
        {
            //just convert it to uppercase for standardization, cipher unchanged either way
            keyword[i] = toupper(keyword[i]);
        }
    }

    //get the message to be encrypted
    string p = get_string("plaintext: ");

    printf("ciphertext: ");

    //loop through and apply vigenere cipher and print out the encrypted message
    for (int i = 0, j = 0, length = strlen(p); i < length; i++, j++)
    {
        //if message part is not alphabetic just simply print it and continue to next cycle
        if (!isalpha(p[i]))
        {
            printf("%c", p[i]);
            j--;
            continue;
        }
        else
        {
            //perform cipher shift
            char z = cipheraddition(p[i], keyword[j % strlen(keyword)]);
            printf("%c", z);
        }
    }
    printf("\n");
    return 0;
}

//performs the required cipher shift
char cipheraddition(char p, char k)
{
    if (isupper(p))
    {
        p = p - 'A';
        k = k - 'A';
        p = (p + k) % 26 + 'A';
        return p;
    }
    else
    {
        p = p - 'a';
        k = k - 'A';
        p = (p + k) % 26 + 'a';
        return p;
    }
}