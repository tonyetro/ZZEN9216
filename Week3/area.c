/*
 * Tony Caelum
 * 5 September 22, ZZEN9216
 * Calculate the area of some 4 sided shapes.
 * Test the functions will produce the right output.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int rectangleArea(int length, int width);
int squareArea(int length, int width);

int main (int argc, char *argv[]) {

    int result = 0;

    // Test the rectangle function
    result = squareArea(2, 5);
    assert(result == 10);

    result = squareArea(1, 8);
    assert(result == 8);

    result = squareArea(50, 100);
    assert(result == 5000);

    result = squareArea(0, 16);
    assert(result == 0);

    result = squareArea(-1, 3);
    assert(result == 0);

    result = squareArea(2, -6);
    assert(result == 0);

    // Test the square function
    result = squareArea(10, 0);
    assert(result == 100);

    result = squareArea(5, 0);
    assert(result == 25);

    result = squareArea(1, 0);
    assert(result == 1);

    result = squareArea(-4, 0);
    assert(result == 0);

    // If we got to this part of the program without an assert error,
    // then all our test cases have passed
    printf("All tests passed. You are awesome!\n");

    return EXIT_SUCCESS;
}

int rectangleArea(int length, int width) {
    return length * width;
}

int squareArea(int length, int width) {
    int area = 0;

    if (length < 0 || width < 0) {
        // Input is invalid. We can't have a negative
        // length, so we will return 0.
    } else if (length > 0 && width == 0) {
        area = length * length;
    } else if (length == width) {
        rectangleArea(length, width);
    }

    return area;
}
