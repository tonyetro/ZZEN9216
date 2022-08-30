/*
 * Print numbers in order
 *
 * Written by Tony Caelum on 27/08/2023
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int num1, num2, num3;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 <= num2 && num2 <= num3) {
        printf("%d %d %d\n", num1, num2, num3); // low mid high
    } else if (num1 <= num3 && num3 <= num2) {
        printf("%d %d %d\n", num1, num3, num2); // low high mid
    } else if (num2 <= num1 && num1 <= num3) {
        printf("%d %d %d\n", num2, num1, num3); // mid low high
    } else if (num2 <= num3 && num3 <= num1) {
        printf("%d %d %d\n", num2, num3, num1); // mid high low
    } else if (num3 <= num1 && num1 <= num2) {
        printf("%d %d %d\n", num3, num1, num2); // high low mid
    } else {
        printf("%d %d %d\n", num3, num2, num1); // high mid low
    }

    return EXIT_SUCCESS;
}
