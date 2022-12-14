/*
 *  pixelColor.h
 *  mandelbrot colors
 *
 *  Created by Richard Buckland on 13/04/11.
 *  Licensed under Creative Commons SA-BY-NC 3.0.
 *
 */

#ifndef PIXELCOLOR_H
#define PIXELCOLOR_H

// Escape steps maximum constant
#define MAX_STEPS 256

unsigned char stepsToRed(int steps);
unsigned char stepsToBlue(int steps);
unsigned char stepsToGreen(int steps);

#endif /* PIXELCOLOR_H */
