/*
 * Tony Caleum
 * 2 September 22, ZZEN9216
 * Print out amount of triangles you can make with the input number
 */

#include <stdlib.h>
#include <stdio.h>

int printTriangle(int rows);

int main(int argc, char *argv[]) {
    int amount;
    scanf("%d", &amount);

    if (amount <= 0) {
        printf("Invalid input. Number must be greater than 0\n");
    } else {
        printf("%d\n", printTriangle(amount));
    }

    return EXIT_SUCCESS;
}

int printTriangle(int rows) {
    int counter = 1, currNumber = 0;

    if (rows == 1) {
        return rows;
    } else {
        while (counter <= rows) {
            currNumber = currNumber + counter;
            if (counter < rows) {
                printf("%d ", currNumber);
            } else if (counter == rows) {
                return currNumber;
            }
            counter++;
        }
    }

    return rows;
}
