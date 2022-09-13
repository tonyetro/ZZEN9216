/*
 * Tony Caleum
 * 2 September 22, ZZEN9216
 * A program that prints a dynamic sized chessboard
 */

#include <stdlib.h>
#include <stdio.h>

void alternatingSymbols(int current);

int main(int argc, char** argv) {
    int size, column, row = 0, counter = 0;
    printf("How large would you like your chessboard today? ");
    scanf("%d", &size);

    if (size == 1) {
        printf("#\n");
    } else {
        while (row < size) {
            column = 0;
            while (column < size) {
                alternatingSymbols(counter);
                counter = counter + 1;
                column = column + 1;
            }
            printf("\n");
            if (size % 2 == 0) {
                counter = counter + 1;
            }
            row = row + 1;
        }
    }

    return EXIT_SUCCESS;
}

void alternatingSymbols(int current) {
    if (current % 2 == 0) {
        printf("#");
    } else {
        printf("O");
    }
}
