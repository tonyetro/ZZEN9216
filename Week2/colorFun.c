// functions to print text in color on unix terminal
// 7 Feb 22 Richard Buckland

#include <stdlib.h>
#include <stdio.h>

#define ESC "\033"
#define SET_FOREGROUND "[38;"
#define RGB_TRIPLE_MODE "2;"
#define ESC_TERMINATOR "m"

// set the color to be used by the terminal in future printing
void setForegroundColor(int red, int green, int blue);

int main (int argc, char *argv[]) {
    setForegroundColor(203, 135, 164);
    printf("so much depends\n");

    setForegroundColor(237, 142, 164);
    printf("upon\n");

    setForegroundColor(255, 145, 128);
    printf("a red wheel\n");

    setForegroundColor(255, 167, 140);
    printf("barrow\n");

    setForegroundColor(255, 203, 135);
    printf("glazed with rain\n");

    setForegroundColor(255, 229, 158);
    printf("water\n");

    setForegroundColor(255, 244, 176);
    printf("beside the white\n");

    setForegroundColor(255, 254, 217);
    printf("chickens\n");

    setForegroundColor(245, 245, 245);
    printf("\nDone!\n");

    return EXIT_SUCCESS;
}

// set the color to be used by the terminal in future printing
void setForegroundColor(int red, int green, int blue) {
    printf(ESC);
    printf(SET_FOREGROUND);
    printf(RGB_TRIPLE_MODE);
    printf("%d;%d;%d", red, green, blue);
    printf(ESC_TERMINATOR);
}
