/*
 * numbers.c
 * This implementation file contains functions only
 * Written by Tony Caelum on 30/08/2022
 */

#include "numbers.h" // Include the header file containing the function prototypes

// Returns TRUE if the number is odd and FALSE otherwise.
int isOdd(int number) {
    int isOddResult = FALSE;
    
    if (number % 2 == 0) {
        isOddResult = FALSE;
    } else {
        isOddResult = TRUE;
    }

    return isOddResult;
}

// Returns TRUE if the number is negative and FALSE otherwise.
int isNegative(int number) {
    int isNegativeResult = FALSE;

    if (number < 0) {
        isNegativeResult = TRUE;
    } else {
        isNegativeResult = FALSE;
    }

    return isNegativeResult;
}

// Returns TRUE if the number is positive and FALSE otherwise.
int isPositive(int number) {
    int isPositiveResult = FALSE;

    if (number > 0) {
        isPositiveResult = TRUE;
    } else {
        isPositiveResult = FALSE;
    }

    return isPositiveResult;
}