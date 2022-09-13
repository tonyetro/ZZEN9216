/*
 * Tony Caleum
 * 2 September 22, ZZEN9216
 * Print the Wondrous Sequence and the number of terms in sequence
 */

#include <stdlib.h>
#include <stdio.h>

int printWondrous(int startingNum);

int main(int argc, char *argv[]) {
    int startingNum = 0;
    scanf("%d", &startingNum);
    int sequenceLength = printWondrous(startingNum);

    if (sequenceLength != 0) {
        printf("The count is %d.\n", sequenceLength);
    } else {
        printf("Invalid input.\n");
    }

    return EXIT_SUCCESS;
}

// Calculate and return the wondrous score of "number"
int printWondrous(int startingNum) {
    // 3 10 5 16 8 4 2 1
    int count = 0;

    if (startingNum == 1) {
        printf("%d\n", startingNum);
        return startingNum;
    } else if (startingNum > 1) {
        printf("%d ", startingNum);
        count = count + 1;

        while (startingNum > 1) {
            if (startingNum % 2 == 0) {
                startingNum = startingNum / 2;

                if (startingNum == 1) {
                    printf("%d\n", startingNum);
                    count = count + 1;
                } else {
                    printf("%d ", startingNum);
                    count = count + 1;
                }

            } else if (startingNum % 2 != 0) {
                startingNum = startingNum * 3 + 1;
                printf("%d ", startingNum);
                count = count + 1;
            }
        }
    }

    return count;
}
