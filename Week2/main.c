/*
 * numbers.c
 * This implementation file contains functions only
 * Written by Tony Caelum on 30/08/2022
 */

#include <stdio.h>
#include <stdlib.h>

#include "numbers.h" // Include the header file to access number functions

int main (int argc, char *argv[]) {

    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);

    printf("Here are some facts about the number %d:\n", number);
    
    // Call the functions defined in numbers.h and implemented in numbers.c
    if (isOdd(number)) {
        printf("It is odd!\n");
    } else {
        printf("It is even!\n");
    }

    if (isPositive(number)) {
        printf("It is positive!\n");
    } else if (isNegative(number)) {
        printf("It is negative!\n");
    } else {
        printf("It is zero!\n");
    }

    return EXIT_SUCCESS;
}