/**
 * CS50 Pset 3
 * recover.c
 *
 * Author: Jeffrey Chiu
 * Program to recover deleted JPEG images on a card
 *
**/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //make sure there is correct number of command line arguments
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    //stores the name of the infile
    char *infile = argv[1];

    //creates a file pointer for the infile
    FILE *inptr = fopen(infile, "r");

    //if file cannot be opened
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    //create buffer to store information
    unsigned char buffer[512];
    //number of images already
    int number = 0;
    FILE *img;

    //while there are chunks fo 512 bytes to be read
    while (fread(buffer, 512, 1, inptr))
    {
        //condition for start of JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if reach another file, close current image
            if (number > 0)
            {
                fclose(img);
            }
            //for name of file image
            char filename[7];
            //string formatting for proper file name
            sprintf(filename, "%03i.jpg", number);
            //open output file pointer
            img = fopen(filename, "w");
            //return if output file is not openable
            if (img == NULL)
            {
                fprintf(stderr, "Could not open %s.\n", filename);
                return 3;
            }
            //increase the number of images read
            number++;

        }
        //as long as its not the no information stuff in the beginning, write it out!
        if (number > 0)
        {
            fwrite(buffer, 512, 1, img);
        }

    }
    fclose(inptr);
    fclose(img);
    return 0;
}