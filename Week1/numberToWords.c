/*
 * 1.8.3 Pronouncing numbers
 *
 * Written by Tony Caelum on 27/08/2023
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int number, ones, tens, hundreds;
    printf("Enter an integer between 0 and 99: ");
    scanf("%d", &number);

    // If number is 0
    if (number == 0) {
        printf("zero\n");
    // If number is out of range
    } else if (number < 0 || number > 999) {
        printf("Number is not between 0..999\n");
    // If number is outside of 'teens', continue
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

            // Incase hundreth is not followed by 0's
            if ((number % 100) / 10 != 0 && hundreds != 0) {
                printf(" and ");
            }

            // Convert number to double digit
            number %= 100;
        }

        // Double digit builder
        tens = 10;
        if (tens >= 20) {
            if (tens < 30) {
                if (number > 19 && number < 30) {
                    printf("twenty\n");
                } else {
                    printf("twenty ");
                }
            } else if (number > 29 && number < 40) {
                if (tens == 20) {
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
        }

        // Finding numbers to print in the teens
        if (tens == 1 || (hundreds / 10) == 1) {
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
        } else {
            // Single digit printer
            ones = number % 10;
            if (ones == 1) {
                printf("one\n");
            } else if (ones == 2) {
                printf("two\n");
            } else if (ones == 3) {
                printf("three\n");
            } else if (ones == 4) {
                printf("four\n");
            } else if (ones == 5) {
                printf("five\n");
            } else if (ones == 6) {
                printf("six\n");
            } else if (ones == 7) {
                printf("seven\n");
            } else if (ones == 8) {
                printf("eight\n");
            } else if (ones == 9) {
                printf("nine\n");
            }
        }
    }

    return EXIT_SUCCESS;
}
