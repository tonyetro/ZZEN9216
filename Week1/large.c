/*
 * Tony Caleum
 * 7 September 22, ZZEN9216
 * Read in two integers and print the larger number
 */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    // Get two integers from stdin
    int num1;
    int num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    if (num1 > num2) {
        printf("%d\n", num1);
    } else if (num1 < num2) {
        printf("%d\n", num2);
    } else {
        printf("%d\n", num1);
    }

    return EXIT_SUCCESS;
}
