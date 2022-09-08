/**
 * bmpShapeDrawing.h
 * Header file for bmpShapeDrawing.c
 * Includes bitmap information (constants) and some pre-defined shape drawing functions
 * Written by Olivia McKeon on 01/08/22
 */

#ifndef BMP_SHAPE_DRAWING_H
#define BMP_SHAPE_DRAWING_H

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

#define IMG_WIDTH 512
#define IMG_HEIGHT 512
#define PIXEL_SIZE 3
#define ROW_STRIDE (IMG_WIDTH * PIXEL_SIZE)

// Sets the RGB (red, green, blue) values of pixel at (x, y) on bitmap
void setPixelRGB(unsigned char *pixelData, int x, int y, unsigned char r, unsigned char g, unsigned char b);

// Sets the colour of pixel at (x, y) on bitmap
// colour parameter uses value associated with #defines
void setPixelColour(unsigned char *pixelData, int colour, int x, int y);

// Draw the background colour of the bitmap
void drawBackground(unsigned char *pixelData, int colour);

// Draws a filled in Rectangle on the bitmap - (x, y) is top left corner
void drawRectangleFilled(unsigned char *pixelData, int colour, int x, int y, int width, int height);

// Draws a Rectangle outline on the bitmap - (x, y) is top left corner
void drawRectangleOutline(unsigned char *pixelData, int colour, int x, int y, int width, int height);

// Draws a filled in Circle on the bitmap
void drawCircleFilled(unsigned char *pixelData, int colour, int x, int y, int radius);

// Draws a Circle outline on the bitmap
void drawCircleOutline(unsigned char *pixelData, int colour, int x, int y, int radius);

// Draws a filled in Triangle on the bitmap
void drawTriangleFilled(unsigned char *pixelData, int colour, int x1, int y1, int x2, int y2, int x3, int y3);

// Draws a Triangle outline on the bitmap
void drawTriangleOutline(unsigned char *pixelData, int colour, int x1, int y1, int x2, int y2, int x3, int y3);

// Draws a line between 2 points - (x1, y1) and (x2, y2)
void drawLine(unsigned char *pixelData, int colour, int x1, int y1, int x2, int y2);

#endif
