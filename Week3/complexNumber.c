/**
 * Print out the result of a complex number, built using structs
 * Written by Tony Caelum on 15/09/22
 */

#include <stdio.h>
#include <stdlib.h>

// 1. Define your struct here (typedef to suit style guide)
typedef struct complexNumber ComplexNumber;

struct complexNumber {
    double real;
    double imaginary;
};

int main(void) {
    // Read in our real and imaginary inputs.
    double real = 0;
    double imaginary = 0;
    scanf("%lf %lf", &real, &imaginary);

    // 2. Create your struct here.
    ComplexNumber cplxNum;
    cplxNum.real = real;
    cplxNum.imaginary = imaginary;

    // 3. Print your struct.
    printf("Real number: %d\n", cplxNum.real);
    printf("Imaginary number: %d\n", cplxNum.imaginary);

    return EXIT_SUCCESS;
}
