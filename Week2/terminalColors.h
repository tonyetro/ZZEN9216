/*
 * 2.3 Terminal color function prototypes
 *
 * Written by Tony Caelum on 31/08/2023
 */

#include <stdlib.h>
#include <stdio.h>

#define ESC "\033"
#define SET_FOREGROUND "[38;"
#define SET_BACKGROUND "[48;"
#define SET_NORMAL "[0"
#define RGB_TRIPLE_MODE "2;"
#define ESC_TERMINATOR "m"

// set the text color
void setForegroundColor(int red, int green, int blue);

// set the background color
void setBackgroundColor(int red, int green, int blue);

// reset to terminal defaults
void resetTextColors(void);
