/*
 * Tony Caelum
 * 27 August 22, ZZEN9216
 * Print 3 numbers from input in order
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int num1, num2, num3;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 <= num2 && num2 <= num3) {
        printf("%d %d %d\n", num1, num2, num3);
    } else if (num1 <= num3 && num3 <= num2) {
        printf("%d %d %d\n", num1, num3, num2);
    } else if (num2 <= num1 && num1 <= num3) {
        printf("%d %d %d\n", num2, num1, num3);
    } else if (num2 <= num3 && num3 <= num1) {
        printf("%d %d %d\n", num2, num3, num1);
    } else if (num3 <= num1 && num1 <= num2) {
        printf("%d %d %d\n", num3, num1, num2);
    } else {
        printf("%d %d %d\n", num3, num2, num1);
    }

    return EXIT_SUCCESS;
}
