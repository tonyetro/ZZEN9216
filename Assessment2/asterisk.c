/*
 * Print out the Mandelbrot Set using asterisks.
 * Created by Alli Murray 06/08/22.
 *
 * Do not submit this file.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define your structs and #defines here.

// Add your functions prototypes here.
void printMandelbrot (double x, double y, int z);

int main (int argc, char *argv[]) {
    // Read in variables from stdin.
    double x;
    double y;
    int z;

    printf("Enter value for x: ");
    scanf("%lf", &x);

    printf("Enter value for y: ");
    scanf("%lf", &y);

    printf("Enter value for z: ");
    scanf("%d", &z);

    printMandelbrot(x, y, z);

    return EXIT_SUCCESS;
}

void printMandelbrot (double x, double y, int z) {
    // WRITE YOUR CODE HERE
}

// Add Mandelbrot Functions from Activity 3.3 here
