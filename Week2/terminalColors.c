/*
 * 2.3 Terminal color function prototypes
 *
 * Written by Tony Caelum on 31/08/2023
 */

#include <stdlib.h>
#include <stdio.h>

#include "terminalColors.h"

// set the text color
void setForegroundColor(int red, int green, int blue) {
    printf(ESC);
    printf(SET_FOREGROUND);
    printf(RGB_TRIPLE_MODE);
    printf("%d;%d;%d", red, green, blue);
    printf(ESC_TERMINATOR);
}

// set the background color
void setBackgroundColor(int red, int green, int blue) {
    printf(ESC);
    printf(SET_BACKGROUND);
    printf(RGB_TRIPLE_MODE);
    printf("%d;%d;%d", red, green, blue);
    printf(ESC_TERMINATOR);
}

// reset to terminal defaults
void resetTextColors(void) {    
    printf(ESC);
    printf(SET_NORMAL);
    printf(ESC_TERMINATOR);
}
