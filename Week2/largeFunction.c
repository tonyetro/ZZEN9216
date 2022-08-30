/*
 * 2.2.1 Print larger (with functions)
 * Written by Tony Caelum on 30/08/2022
 */

#include <stdio.h>
#include <stdlib.h>

int larger(int num1, int num2);

int main (int argc, char *argv[]) {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("%d\n", larger(num1, num2));

    return EXIT_SUCCESS;
}

int larger(int num1, int num2) {
    return num1 >= num2 ? num1 : num2;
}
