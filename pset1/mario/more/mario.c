/*
* Jeffrey Chiu
* CS-50-Problem Set 1 mario.c
* Generates a full-pyramid like that in Mario using nested for loops
*/
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = -1;
    //make sure height constraints are met
    while (height < 0 || height > 23)
    {
        printf("Height: ");
        height = get_int();
    }
    //loop though each layer one by one
    for (int i = 0; i < height; i++)
    {
        //prints the initial empty spaces
        for (int j = height - 1 - i; j > 0; j--)
        {
            printf(" ");
        }
        //print the hashmarks on the left side
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }
        //print the spaces in between each side
        printf("  ");
        //print the hashmarks on the right side
        for (int m = 0; m <= i; m++)
        {
            printf("#");
        }
        //on to the next line
        printf("\n");
    }
}