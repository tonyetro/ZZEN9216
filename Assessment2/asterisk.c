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

#define SIZE 64
#define MAX_STEPS 256

typedef struct complexNumber ComplexNumber;

// Complex number struct, built with a real number component and
// an imaginary number component
struct complexNumber {
    double realComp;
    double imaginaryComp;
};

ComplexNumber mandelbrotAdd(ComplexNumber c1,
                            ComplexNumber c2);
ComplexNumber mandelbrotSquare(ComplexNumber c);
double mandelbrotMagnitude(ComplexNumber c);
int escapeSteps(double x, double y);
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
    double pixelDistance = pow(2, -z);
    int half = SIZE / 2;
    int row = half;
    int col = -half;

    // code to print in columns
    while (row > -half) {
        col = -half;
        // code to print in rows
        while (col < half) {
            if (escapeSteps(
                (col * pixelDistance) + x,
                (row * pixelDistance) + y) < MAX_STEPS) {
                printf(" ");
            } else {
                printf("*");
            }
            col = col + 1;
        }
        printf("\n");
        row = row - 1;
    }
}

int escapeSteps(double x, double y) {
    int counter = 0;
    double magnitude = 0;
    ComplexNumber originPoint, complexNum;
    originPoint.realComp = 0;
    originPoint.imaginaryComp = 0;
    complexNum.realComp = x;
    complexNum.imaginaryComp = y;

    while (counter < MAX_STEPS) {
        if (magnitude <= 2) {
            originPoint = mandelbrotSquare(originPoint);
            originPoint = mandelbrotAdd(originPoint, complexNum);
            magnitude = mandelbrotMagnitude(originPoint);
        } else {
            counter = MAX_STEPS; // Escape while loop
        }

        counter = counter + 1;
    }

    return counter;
}

ComplexNumber mandelbrotAdd(ComplexNumber c1,
                            ComplexNumber c2) {
    ComplexNumber cplxNum;
    cplxNum.realComp = c1.realComp + c2.realComp;
    cplxNum.imaginaryComp = c1.imaginaryComp + c2.imaginaryComp;
    return cplxNum;
}

ComplexNumber mandelbrotSquare(ComplexNumber c) {
    ComplexNumber cplxNum;
    cplxNum.realComp = pow(c.realComp, 2) - pow(c.imaginaryComp, 2);
    cplxNum.imaginaryComp = 2 * c.realComp * c.imaginaryComp;
    return cplxNum;
}

double mandelbrotMagnitude(ComplexNumber c) {
    return sqrt(pow(c.realComp, 2) + pow(c.imaginaryComp, 2));
}
