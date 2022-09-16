/**
 * Testing all mandelbrot functions (square, add, magnitude and escape)
 * Written by Tony Caelum on 16/09/22
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 256

typedef struct complexNumber ComplexNumber;

// Complex number struct, built with a real number component and
// an imaginary number component
struct complexNumber {
    double realComp;
    double imaginaryComp;
};

// Function declarations.
struct complexNumber mandelbrotAdd(struct complexNumber c1,
                                   struct complexNumber c2);
struct complexNumber mandelbrotSquare(struct complexNumber c);
double mandelbrotMagnitude(struct complexNumber c);
int escapeSteps(double x, double y);

// DO NOT MODIFY THE MAIN FUNCTION - this automarker might fail you
int main (void) {
    // Read in test coordinates.
    double x = 0;
    double y = 0;
    scanf("%lf %lf", &x, &y);

    printf("%d\n", escapeSteps(x, y));

    return EXIT_SUCCESS;
}

int escapeSteps(double x, double y) {
    int counter = 0;
    double magnitude = 0;
    ComplexNumber originPoint, complexNum;
    originPoint.realComp = 0;
    originPoint.imaginaryComp = 0;
    complexNum.realComp = x;
    complexNum.imaginaryComp = y;

    while (counter < MAX_ITERATIONS) {
        if (magnitude <= 2) {
            originPoint = mandelbrotSquare(originPoint);
            originPoint = mandelbrotAdd(originPoint, complexNum);
            magnitude = mandelbrotMagnitude(originPoint);
        } else {
            break;
        }

        counter = counter + 1;
    }

    return magnitude;
}

struct complexNumber mandelbrotAdd(struct complexNumber c1,
                                   struct complexNumber c2) {
    ComplexNumber cplxNumAdd;
    cplxNumAdd.realComp = c1.realComp + c2.realComp;
    cplxNumAdd.imaginaryComp = c1.imaginaryComp + c2.imaginaryComp;
    return cplxNumAdd;
}

struct complexNumber mandelbrotSquare(struct complexNumber c) {
    ComplexNumber cplxNumSquare;
    cplxNumSquare.realComp = pow(c.realComp, 2) - pow(c.imaginaryComp, 2);
    cplxNumSquare.imaginaryComp = 2 * c.realComp * c.imaginaryComp;
    return cplxNumSquare;
}

double mandelbrotMagnitude(struct complexNumber c) {
    return sqrt(pow(c.realComp, 2) + pow(c.imaginaryComp, 2));
}
