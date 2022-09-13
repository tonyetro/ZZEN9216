/*
 * Tony Caleum
 * 2 September 22, ZZEN9216
 * Print a line for each time the lyrics "Around The World" plays
 * in the song "Daft Punk - Around The World"
 */

#include <stdlib.h>
#include <stdio.h>

void aroundTheWorld(int numLines);

int main (int argc, char *argv[]) {

    int numLines = 0;
    printf("Enter number of song lines: ");
    scanf("%d", &numLines);
    aroundTheWorld(numLines);

    return EXIT_SUCCESS;
}

void aroundTheWorld(int numLines) {
    for (int counter = 1; counter < numLines; counter++) {
        counter = counter + 1;
        if (numLines == 1) {
            printf("Around the world.\n");
        } else if (counter == 1 && numLines > 1) {
            printf("Around the world,\n");
        } else if (counter > 1 && counter < numLines) {
            printf("around the world,\n");
        } else if (counter == numLines) {
            printf("around the world.\n");
        }
    }
}
