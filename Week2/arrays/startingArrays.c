/*
 * Tony Caelum
 * 3 September 22, ZZEN9216
 * A program to help understand the basics of arrays in C
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 5

// prints the array details (index and value)
void printArray(int array[], int arraySize);

int main(int argc, char** argv) {
    // int intArray[ARRAY_SIZE] = {67, 121, 98, 101, 114};
    // printArray(intArray, ARRAY_SIZE);
    int intArray[ARRAY_SIZE] = {};
    int index = 0;

    printf("Scanning in array values:\n");
    while (index < ARRAY_SIZE) {
        printf("Enter array value at index %d: ", index);
        scanf("%d", &intArray[index]);
        index++;
    }
    printf("\n");

    printArray(intArray, ARRAY_SIZE);
    printf("\n");

    printf("The hidden word is: ");
    index = 0;
    while (index < ARRAY_SIZE) {
        printf("%c", intArray[index]);
        index++;
    }
    printf("\n");

    return EXIT_SUCCESS;
}

// prints the array details (index and value)
void printArray(int array[], int arraySize) {
    int counter = 0;
    printf("Printing the array details:\n");

    while (counter < arraySize) {
        printf("Index: %d\tValue: %d\n", counter, array[counter]);
        counter++;
    }
}
