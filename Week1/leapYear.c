/*
 * 1.8.4 Bad Code
 *
 * Written by Tony Caelum on 28/08/2023
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int year = 0;
    int leapYear = 0;
    printf("Enter a year: ");
    scanf("%d", &year);

    if (year % 4 != 0) {
        leapYear = 0; // First 'NO'
    } else {
        if (year % 100 != 0) {
            leapYear = 1; // First 'YES'
        } else {
            if (year % 400 != 0) {
                leapYear = 0; // Second 'NO'
            } else {
                leapYear = 1; // Second 'YES'
            }
        }
    }

    printf("%d is ", year);
    if (leapYear == 0) {
        printf("not ");
    }
    printf("a leap year\n");

    return 0;
}
