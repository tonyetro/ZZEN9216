/**
 * Testing all mandelbrot functions (square, add, magnitude and escape)
 * Written by Tony Caelum on 16/09/22
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations.
struct complexNumber mandelbrotAdd(struct complexNumber c1,
                                   struct complexNumber c2);
struct complexNumber mandelbrotSquare(struct complexNumber c);
double mandelbrotMagnitude(struct complexNumber c);
int escapeSteps(double x, double y);

// DO NOT MODIFY THE MAIN FUNCTION - you might cause the automarker to fail you.
int main (void) {
    // Read in test coordinates.
    double x = 0;
    double y = 0;
    scanf("%lf %lf", &x, &y);

    printf("%d\n", escapeSteps(x, y));

    return EXIT_SUCCESS;
}

int escapeSteps(double x, double y) {
    // TODO: write this function.
}

struct complexNumber mandelbrotAdd(struct complexNumber c1,
                                   struct complexNumber c2) {
    // TODO: write this function.
}

struct complexNumber mandelbrotSquare(struct complexNumber c) {
    // TODO: write this function.
}

double mandelbrotMagnitude(struct complexNumber c) {
    // TODO: write this function.
}
