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
#include <string.h>

#define MAX_INPUT_SIZE 256

int main(int argc, char *argv[]) {

    // read from stdin and store the value as a string called "little"
    char *little = malloc(MAX_INPUT_SIZE);
    printf("Enter little-endian bytes: ");
    fgets(little, MAX_INPUT_SIZE, stdin);

    // TODO:
    // Your code goes here
    // 0x00 0x00 0xf7 0x2c

    int strLength = strlen(little) - 2;
    char *result = {0};

    // If input contains space (ASCII = 20), do calculations
    int idx = strLength;

    if (strchr(little, ' ')) {
        while (0 != idx) {
            if (little[idx] == ' ') {
                printf("%d: ' '\n", idx);
                idx = idx - 1;
            }

            printf("%d: 0x00 0x00 0xf7 0x2c\n", idx);
            idx = idx - 1;
        }
    }

    // replace this print statement with your own once you have converted the string.
    printf("%s\n", little);
    printf("%s\n", result);

    free(little);

    return 0;
}
