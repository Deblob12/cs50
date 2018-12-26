#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <math.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize scale infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];
    float scale = atof(argv[1]);
    int small = floor(1 / scale);
    if (scale < 0 || scale > 100)
    {
        fprintf(stderr, "Usage: scale is in (0.0, 100.0]\n");
        return 1;
    }
    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 1;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 1;
    }
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 1;
    }
    //temporarily set new file headers to old ones
    BITMAPFILEHEADER bf1 = bf;
    BITMAPINFOHEADER bi1 = bi;
    //rescale
    bi1.biWidth *= scale;
    bi1.biHeight *= scale;

    //repad
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding1 = (4 - (bi1.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //change image sizes
    bi1.biSizeImage = abs(bi1.biHeight) * (bi1.biWidth * sizeof(RGBTRIPLE) + padding1);
    bf1.bfSize = (bi1.biSizeImage + 54);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf1, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi1, sizeof(BITMAPINFOHEADER), 1, outptr);

    if (scale >= 1)
    {


        // iterate over infile's scanlines
        for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
        {
            //print each scan line n times high
            for (int t = 0; t < scale; t++)
            {
                //set to beginning of RGBs
                fseek(inptr, 54 + (bi.biWidth * 3 + padding) * i, SEEK_SET);
                for (int j = 0; j < bi.biWidth; j++)
                {
                    // temporary storage
                    RGBTRIPLE triple;

                    // read RGB triple from infile
                    fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                    //write each RGB n times
                    for (int z = 0; z < scale; z ++)
                    {
                        // write RGB triple to outfile
                        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    }
                }
                // skip over padding, if any
                fseek(inptr, padding, SEEK_CUR);

                // then add back new padding
                for (int k = 0; k < padding1; k++)
                {
                    fputc(0x00, outptr);
                }
            }
            // iterate over pixels in scanline
        }
    }
    else
    {
        // iterate over infile's scanlines
        for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
        {
            //set to beginning of RGBs
            fseek(inptr, 54 + (bi.biWidth * 3 + padding) * i, SEEK_SET);
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile

                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                if (i % small == 0 && j % small == 0)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }

            }
            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);

            // then add back new padding
            if (i % small == 0)
            {
                for (int k = 0; k < padding1; k++)
                {
                    fputc(0x00, outptr);
                }
            }
        }
        // iterate over pixels in scanline
    }
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    return 0;
    fclose(outptr);
}
