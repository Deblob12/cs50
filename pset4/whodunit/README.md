# Questions

## What's `stdint.h`?

The <stdint.h> header allows for sets of integers with exact widths.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

It allows the program to get the exact amount of bit.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE = 1 byte
DWORD = 4 bytes
LONG = 4 bytes
WORD = 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

0x4d42

## What's the difference between `bfSize` and `biSize`?

bfSize is the size of the BITMAPFILEHEADER and biSize is the size of the BITMAPINFODHEADER

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

The file might not be openable or just simply does not exist

## Why is the third argument to `fread` always `1` in our code?

Because we only want to read a chunk of information equal to the size of BITMAPFILEHEADER and BITMAPINFOHEADER

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

It sets the stream to a certain amount of offset from a given location

## What is `SEEK_CUR`?

Current position of the file pointer

## Whodunit?

It was Professor Plum with the candlestick in the library.
