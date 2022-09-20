// print a circle to terminal
// x^2 + y^2 = r^2

#include <stdio.h>
#include <stdlib.h>

#define SIZE 16
#define RADIUS 5

int main (int argc, char *argv[]) {
    
    
    // 1. initialise
    int half = SIZE / 2;
    int row = half; // 10
    int col = -half; //10
    // 2. end condition
    while (row > -half) {
        // 3. repeated
        col = -half;
        while (col < SIZE) {
            if (((col * col) + (row * row)) <= (RADIUS * RADIUS)) {
                printf("*");
            } else {
                printf(" ");
            }
            col = col + 1;
        }
        printf("\n");
        row = row - 1;
    } 
    return EXIT_SUCCESS;
}