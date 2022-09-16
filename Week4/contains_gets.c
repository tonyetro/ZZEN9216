/**
 * Tony Caleum
 * 16 September 22, ZZEN9216
 * This program reads through a file (file.c) line-by-line, checking if
 * it contains use of the gets() function in the code.
 * If the file contains one or more uses of gets(), an alert is printed.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 255

int line_contains_gets(char *line);

int main(void) {

    // open a file in read mode
    FILE *input_file_pointer = fopen("file.c", "r");

    // create a buffer for the lines to be stored in
    // note the buffer is overwritten each time a new line is read
    char buffer[MAX_LINE_LENGTH];

    // fgets() is "secure", since we specify the max length of the buffer
    // we are writing to
    while(fgets(buffer, MAX_LINE_LENGTH, input_file_pointer)) {

        int result = line_contains_gets(buffer);

        // if there is an occurrence of gets() in the line
        if (result != 0) {
            printf("Alert! This file has at least one occurrence of gets()!\n");

            // exit the program. we've done our job!
            return 0;
        }
    }

    fclose(input_file_pointer);
    return 0;
}

// TODO: Write this function
// check if a line contains the gets() function
// if it does,    return 1
// if it doesn't, return 0
int line_contains_gets(char *line) {

    return 0;
}
