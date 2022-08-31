/*
 * 1.8.3 Pronouncing numbers
 *
 * Written by Tony Caelum on 27/08/2023
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int number, lastDigit;
    printf("Enter an integer between 0 and 99: ");
    scanf("%d", &number);
    lastDigit = number % 10;

    // First end case - if number is 0
    if (number == 0) {
        printf("zero\n");
    } else if (number < 0 || number > 99) {
        printf("Number is not between 0..99\n");
    } else {
        // Double digit builder
        if (number > 19 && number < 30) {
            if (number == 20) {
                printf("twenty\n");
            } else {
                printf("twenty ");
            }
        } else if (number > 29 && number < 40) {
            if (number == 30) {
                printf("thirty\n");
            } else {
                printf("thirty ");
            }
        } else if (number > 39 && number < 50) {
            if (number == 40) {
                printf("forty\n");
            } else {
                printf("forty ");
            }
        } else if (number > 49 && number < 60) {
            if (number == 50) {
                printf("fifty\n");
            } else {
                printf("fifty ");
            }
        } else if (number > 59 && number < 70) {
            if (number == 60) {
                printf("sixty\n");
            } else {
                printf("sixty ");
            }
        } else if (number > 69 && number < 80) {
            if (number == 70) {
                printf("seventy\n");
            } else {
                printf("seventy ");
            }
        } else if (number > 79 && number < 90) {
            if (number == 80) {
                printf("eighty\n");
            } else {
                printf("eighty ");
            }
        } else if (number > 89 && number < 100) {
            if (number == 90) {
                printf("ninety\n");
            } else {
                printf("ninety ");
            }
        }

        // Finding numbers to print in the teens
        if (number > 9 && number < 20) {
            if (number == 10) {
                printf("ten\n");
            } else if (number == 11) {
                printf("eleven\n");
            } else if (number == 12) {
                printf("twelve\n");
            } else if (number == 13) {
                printf("thirteen\n");
            } else if (number == 14) {
                printf("fourteen\n");
            } else if (number == 15) {
                printf("fifteen\n");
            } else if (number == 16) {
                printf("sixteen\n");
            } else if (number == 17) {
                printf("seventeen\n");
            } else if (number == 18) {
                printf("eighteen\n");
            } else if (number == 19) {
                printf("nineteen\n");
            }
            // Singular number cherry picking
        } else {
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
