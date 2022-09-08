/*
 * 1.8.3 Pronouncing numbers
 *
 * Written by Tony Caelum on 27/08/2023
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int number, lastDigit, tens, hundreds;
    printf("Enter an integer between 0 and 99: ");
    scanf("%d", &number);
    lastDigit = number % 10;

    // If number is 0
    if (number == 0) {
        printf("zero\n");
        // If number is out of range
    } else if (number < 0 || number > 999) {
        printf("Number is not between 0..99\n");
        // If number is outside 'teens', continue
    } else {
        // Triple digit builder
        hundreds = number / 100;
        if (hundreds >= 1 && hundreds <= 9) {
            if (hundreds == 1) {
                printf("one hundred");
            } else if (hundreds == 2) {
                printf("two hundred");
            } else if (hundreds == 3) {
                printf("three hundred");
            } else if (hundreds == 4) {
                printf("four hundred");
            } else if (hundreds == 5) {
                printf("five hundred");
            } else if (hundreds == 6) {
                printf("six hundred");
            } else if (hundreds == 7) {
                printf("seven hundred");
            } else if (hundreds == 8) {
                printf("eight hundred");
            } else if (hundreds == 9) {
                printf("nine hundred");
            }

            // Incase hundreds is not followed by 0's
            if ((number % 100) == 0 && (number % 10) == 0) {
                printf("\n");
            } else {
                printf(" and ");
            }
        }

        // Double digit builder
        tens = (number % 100) / 10;
        // Every double digit range except the teens
        if (tens > 1) {
            if (tens == 2) {
                printf("twenty");
            } else if (tens == 3) {
                printf("thirty");
            } else if (tens == 4) {
                printf("forty");
            } else if (tens == 5) {
                printf("fifty");
            } else if (tens == 6) {
                printf("sixty");
            } else if (tens == 7) {
                printf("seventy");
            } else if (tens == 8) {
                printf("eighty");
            } else if (tens == 9) {
                printf("ninety");
            }

            if ((number % 100 != 0) && (number % 10 != 0) &&
                lastDigit != 0) {
                printf(" ");
            } else {
                printf("\n");
            }
        }

        // Finding numbers to print in the teens
        if (tens == 1) {
            if (lastDigit == 0) {
                printf("ten\n");
            } else if (lastDigit == 1) {
                printf("eleven\n");
            } else if (lastDigit == 2) {
                printf("twelve\n");
            } else if (lastDigit == 3) {
                printf("thirteen\n");
            } else if (lastDigit == 4) {
                printf("fourteen\n");
            } else if (lastDigit == 5) {
                printf("fifteen\n");
            } else if (lastDigit == 6) {
                printf("sixteen\n");
            } else if (lastDigit == 7) {
                printf("seventeen\n");
            } else if (lastDigit == 8) {
                printf("eighteen\n");
            } else if (lastDigit == 9) {
                printf("nineteen\n");
            }
        } else {
            // Singular number cherry picking
            if (lastDigit == 1) {
                printf("one\n");
            } else if (lastDigit == 2) {
                printf("two\n");
            } else if (lastDigit == 3) {
                printf("three\n");
            } else if (lastDigit == 4) {
                printf("four\n");
            } else if (lastDigit == 5) {
                printf("five\n");
            } else if (lastDigit == 6) {
                printf("six\n");
            } else if (lastDigit == 7) {
                printf("seven\n");
            } else if (lastDigit == 8) {
                printf("eight\n");
            } else if (lastDigit == 9) {
                printf("nine\n");
            }
        }
    }

    return EXIT_SUCCESS;
}
