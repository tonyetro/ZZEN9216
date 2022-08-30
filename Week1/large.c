/*
 * Read in two integers and print the larger.
 *
 * Written by Tony Caelum on 27/08/2022
 */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    // Get two integers from stdin
    int num1;
    int num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // YOUR CODE GOES here
    printf("%d\n", num1 > num2 ? num1 : num2);

    return EXIT_SUCCESS;
}
