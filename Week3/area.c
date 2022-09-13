/**
 * Calculate the area of some 4 sided shapes.
 * Test the functions will produce the right output.
 * Written by Tony Caelum on 05/09/22
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int rectangleArea (int length, int width);
int squareArea (int side);

int main (int argc, char *argv[]) {
    int result = 0;

    // Test the rectangle function
    result = rectangleArea(2, 5);
    assert(result == 10);

    result = rectangleArea(1, 8);
    assert(result == 8);

    result = rectangleArea(50, 100);
    assert(result == 5000);

    result = rectangleArea(0, 16);
    assert(result == 0);

    result = rectangleArea(-1, 3);
    assert(result == 0);

    result = rectangleArea(2, -6);
    assert(result == 0);

    // Test the square function
    result = squareArea(10);
    assert(result == 100);

    result = squareArea(5);
    assert(result == 25);

    result = squareArea(1);
    assert(result == 1);

    result = squareArea(-4);
    assert(result == 0);

    // If we got to this part of the program without an assert error,
    // then all our test cases have passed
    printf("All tests passed. You are awesome!\n");

    return EXIT_SUCCESS;
}

int rectangleArea(int length, int width) {
    int area = 0;

    if (length < 0 || width < 0) {
        // Input is invalid. We can't have a negative
        // length, so we will return 0.
    } else {
        area = length * width;
    }

    return area;
}

int squareArea(int side) {
    return rectangleArea(side, side);
}
