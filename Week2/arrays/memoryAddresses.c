// A program to help understand how memory is allocated with an array
// 01/08/22 Olivia McKeon

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 10

void printArrayDetails(int* array, int size);
void startingArrayValues(int* array);

int main(int argc, char** argv) {
    int* array;
    array = malloc(sizeof(*array) * ARRAY_SIZE);
    startingArrayValues(array);

    printArrayDetails(array, ARRAY_SIZE);

    free(array);
    return EXIT_SUCCESS;
}

// prints the index, value and memory address for each element of array
void printArrayDetails(int* array, int size) {
    int index;
    printf("\n");
    printf("Memory address (array pointer): %p\n\n", array);
    printf("Index\t\tValue\t\tMemory Address\n\n");
    index = 0;
    while (index < size) {
        printf("%d\t\t%d\t\t%p\n", index, array[index], &array[index]);
        index = index + 1;
    }
    printf("\n");
}

// Initialises the starting values for the array in this activity
// Note: do not change these values
void startingArrayValues(int* array) {
    array[0] = -67;
    array[1] = 121;
    array[2] = -98;
    array[3] = 114;
    array[4] = -32;
    array[5] = -83;
    array[6] = -99;
    array[7] = 114;
    array[8] = 116;
    array[9] = 121;
}
