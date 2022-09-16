/**
 * Tony Caleum
 * 16 September 22, ZZEN9216
 * A program to filter out unwanted characters in a string
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE (!FALSE)
#define BUFFER_SIZE 256  // string buffer for the input string from the terminal

int allowedASCIIChar(int asciiValue);
int numAllowedChars(char* inputStr, int length);
char* santitiseString(char* inputStr, int length);

int main(int argc, char** argv) {
    // You can use this code to test your implementation of the santitiseString function
    // Note: do not change this code in main (or make sure to keep a reference of it for when you submit)
    char inputStr[BUFFER_SIZE];
    char* outputStr;

    printf("Let's read in a string to sanitise!\n");
    printf("Input string: ");
    scanf("%[^\n]s", inputStr);

    outputStr = santitiseString(inputStr, strlen(inputStr));
    printf("\n");
    printf("Before sanitising:\t%s\n", inputStr);
    printf("After sanitising:\t%s\n", outputStr);

    free(outputStr);

    return EXIT_SUCCESS;
}

// function to check if characters are: 0-9, A-Z and a-z
int allowedASCIIChar(int asciiValue) {
    if (asciiValue >= 48 && asciiValue <= 57) {  // checking: 0 to 9
        return TRUE;
    } else if (?) {  // checking: A to Z
        return TRUE;
    } else if (?) {  // checking: a to z
        return TRUE;
    }
    return FALSE;
}

// count the number of allowed characters in the input string
int numAllowedChars(char* inputStr, int length) {
    int count;       // number of allowed characters from input
    int asciiValue;  // value of ASCII character
    int index;       // index of input array

    // WRITE YOUR CODE HERE
}

// function to remove characters other than 0-9, a-z and A-Z
char* santitiseString(char* inputStr, int length) {
    int count;        // number of allowed characters from input
    int indexOutput;  // index of output array
    int indexInput;   // index of input array
    int asciiValue;   // value of ASCII character
    char* outputStr;  // string buffer for output string (character array)

    // WRITE YOUR CODE HERE

    // Step 6.3: Allocate the required memory for outputStr
    outputStr = malloc(sizeof(*outputStr) * count);

    // WRITE YOUR CODE HERE
}
