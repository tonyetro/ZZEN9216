// Write a program that converts little-endian addresses to big-endian addresses.

// Input: Standard input (stdin) that contains a series of hexadecimal characters,
// e.g., "0x00 0x00 0xf7 0x2c"

// Output: print to standard output (stdout) the bytes represented in big-endian format

// Examples:
// In:  0x00 0x00 0xf7 0x2c
// Out: 0x2c 0xf7 0x00 0x00

// In: 0x42
// Out 0x42

// Expect no leading or trailing whitespace.
// Your program does not have to account for invalid hexadecimal characters (e.g., 0xtz)

#include <stdlib.h>
#include <stdio.h>

#define MAX_INPUT_SIZE 256

int main (int argc, char *argv[]) {

    // read from stdin and store the value as a string called "little"
    char *little = malloc(MAX_INPUT_SIZE);
    printf("Enter little-endian bytes: ");
    fgets(little, MAX_INPUT_SIZE, stdin);

    // TODO:
    // Your code goes here


    // replace this print statement with your own once you have converted the string.
    // printf("%s\n", YOUR_BIG-ENDIAN_STRING);

    free(little);

    return 0;
}
