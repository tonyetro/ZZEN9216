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

void printMandelbrot(double x, double y, int z) {
    // WRITE YOUR CODE HERE
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
