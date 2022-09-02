/*
 * Tony Caleum
 * 2 September 22, ZZEN9216
 * Print out amount of triangles you can make with number that was input
 */

#include <stdlib.h>
#include <stdio.h>

int printTriangle(int rows);

int main(int argc, char *argv[]) {
    int amount, counter = 1, currNumber = 0;
    scanf("%d", &amount);

    if (amount <= 0) {
        printf("Invalid input. Number must be greater than 0\n");
    } else {
        if (amount == 1) {
            printf("1\n");
        } else {
            while (counter <= amount) {
                currNumber = currNumber + counter;
                if (counter < amount) {
                    printf("%d ", currNumber);
                } else if (counter == amount) {
                    printf("%d\n", currNumber);
                }
                counter++;
            }
        }
    }

    return EXIT_SUCCESS;
}
