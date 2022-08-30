/*
 * terminalColors.h
 * Functional logic for terminal colors in coloured terminal poem
 * Written by Tony Caelum on 30/08/2022
 */

#define ESC "\033"
#define SET_FOREGROUND "[38;"
#define RGB_TRIPLE_MODE "2;"
#define ESC_TERMINATOR "m"

#include <stdio.h>
#include "terminalColors.h"

// set the color to be used by the terminal in future printing
void setForegroundColor(int red, int green, int blue) {
    printf(ESC);
    printf(SET_FOREGROUND);
    printf(RGB_TRIPLE_MODE);
    printf("%d;%d;%d", red, green, blue);
    printf(ESC_TERMINATOR);
}
