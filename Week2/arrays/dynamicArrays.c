/*
 * Tony Caelum
 * 4 September 22, ZZEN9216
 * A program to help understand how to work with dynamic arrays in C
 * Goal: Change the integer array so the "hidden text" prints correctly
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 14

void absolute(int* array, int size);
void insert(int* array, int size, int value, int idx);
void fixHiddenWords(int* array, int size);
void printArrayAsInts(int* array, int size);
void printArrayAsChars(int* array, int size);
void printHiddenWords(int* array, int size);
void startingArrayValues(int* array);

int main(void) {
    int* array;
    array = malloc(sizeof(*array) * ARRAY_SIZE);
    startingArrayValues(array);

    fixHiddenWords(array, ARRAY_SIZE);

    // printArrayAsInts(array, ARRAY_SIZE);
    // printArrayAsChars(array, ARRAY_SIZE);

    printHiddenWords(array, ARRAY_SIZE);

    free(array);
    return EXIT_SUCCESS;
}

// converts all negative values in array to positive values
void absolute(int* array, int size) {
    int index = 0;
    while (index < size) {
        if (array[index] < 0) {
            array[index] = array[index] * -1;
        }
        index++;
    }
}

// inserts the 'value' into the array at index 'idx'
void insert(int* array, int size, int value, int idx) {
    int index = size - 1;
    while (index > idx) {
        array[index] = array[index - 1];
        index--;
    }
    array[idx] = value;
}

// uses the 'absolute' and 'insert' functions to fix the array values
void fixHiddenWords(int* array, int size) {
    int index;
    absolute(array, size);

    index = 0;
    while (index < size) {
        // Insert first 'e' vowel
        if (array[index] == 114 && array[index - 1] == 98) {
            insert(array, size, 101, index);
            // Insert second 'e' vowel
        } else if (array[index] == 99 && array[index - 1] == 83) {
            insert(array, size, 101, index);
            // Insert 'u' vowel
        } else if (array[index] == 114 && array[index - 1] == 99) {
            insert(array, size, 117, index);
            // Insert 'i' vowel (checks
        } else if (array[index] == 116 && array[index - 1] == 114) {
            insert(array, size, 105, index);
        }
        index++;
    }
}

// prints the array values as integers
void printArrayAsInts(int* array, int size) {
    int index;
    printf("Index\tValue\n");
    index = 0;
    while (index < size) {
        printf("%d\t%d\n", index, array[index]);
        index++;
    }
}

// prints the array values as 'characters'
void printArrayAsChars(int* array, int size) {
    int index;
    printf("Index\tValue\n");
    index = 0;
    while (index < size) {
        printf("%d\t%c\n", index, array[index]);
        index++;
    }
}

// prints the hidden words
void printHiddenWords(int* array, int size) {
    int index;
    printf("The hidden text is: ");
    index = 0;
    while (index < size) {
        printf("%c", array[index]);
        index++;
    }
    printf("\n");
}

// Initialises the starting values for the array in this activity
// Note: do not change these values
void startingArrayValues(int* array) {
    array[0] = -67; // C
    array[1] = 121; // y
    array[2] = -98; // b
    array[3] = 114; // r
    array[4] = -32; // (space)
    array[5] = -83; // S
    array[6] = -99; // c
    array[7] = 114; // r
    array[8] = 116; // t
    array[9] = 121; // y
    array[10] = 0;
    array[11] = 0;
    array[12] = 0;
    array[13] = 0;
}
