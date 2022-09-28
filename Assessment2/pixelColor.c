/**
 * Helper functions to assign different R, G and B values
 *
 * Written by Tony Caelum 15/09/22
 * Created by Richard Buckland on 13/04/11.
 * Licensed under Creative Commons SA-BY-NC 3.0.
 */

#include "pixelColor.h"

unsigned char stepsToBlue(int steps) {
    // Static value to keep strong blue presence
    return 255;
}

unsigned char stepsToGreen(int steps) {
    // Returns value from 255 and going lower
    // trying to keep green presence down
    int colorCode = (256 - steps);
    return colorCode;
}

unsigned char stepsToRed(int steps) {
    // Varying value from 0-255 to help blue/pink gradients
    return steps;
}
