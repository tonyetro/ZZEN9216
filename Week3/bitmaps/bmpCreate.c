/**
 * bmpShapeDrawing.c
 * Pre-defined shape drawing functions, to make it simpler to create your amazing bitmap artwork!
 * Note: You do not need to understand the code used in this file, but you are welcome to look through it.
 * Written by Olivia McKeon on 01/08/22
 */

#include "bmpShapeDrawing.h"

int _pixelOnBitmap(int x, int y);
int _pixelInCircle(int x, int y, int centreX, int centreY, int radius);
int _pixelInTriangle(int px, int py, int x1, int y1, int x2, int y2, int x3, int y3);
int _min(int *values, int size);
int _max(int *values, int size);

// *****************************
// ***** public functions *****
// *****************************

// Draw the background colour of the bitmap
void drawBackground(unsigned char *pixelData, int colour) {
    for (int y = 0; y < IMG_HEIGHT; y++) {
        for (int x = 0; x < IMG_WIDTH; x++) {
            setPixelColour(pixelData, colour, x, y);
        }
    }
}

// Draws a filled in Rectangle on the bitmap - (x, y) is top left corner
void drawRectangleFilled(unsigned char *pixelData, int colour, int x, int y, int width, int height) {
    int pxStart = x;
    int pxEnd = x + width;
    int pyStart = y;
    int pyEnd = y + height;
    for (int py = pyStart; py < pyEnd; py++) {
        for (int px = pxStart; px < pxEnd; px++) {
            if (_pixelOnBitmap(px, py)) {
                setPixelColour(pixelData, colour, px, py);
            }
        }
    }
}

// Draws a Rectangle outline on the bitmap - (x, y) is top left corner
void drawRectangleOutline(unsigned char *pixelData, int colour, int x, int y, int width, int height) {
    for (int px = x; px < x + width; ++px) {
        for (int py = y; py < y + height; ++py) {
            if (_pixelOnBitmap(px, py)) {
                if (px >= x + 1 && px < (x + width) - 1 && py >= y + 1 && py < (y + height) - 1) {
                    continue;
                }
                setPixelColour(pixelData, colour, px, py);
            }
        }
    }
}

// Draws a filled in Circle on the bitmap
void drawCircleFilled(unsigned char *pixelData, int colour, int x, int y, int radius) {
    int pxStart = x - radius;
    int pxEnd = x + radius;
    int pyStart = y - radius;
    int pyEnd = y + radius;
    for (int py = pyStart; py <= pyEnd; py++) {
        for (int px = pxStart; px <= pxEnd; px++) {
            if (_pixelOnBitmap(px, py)) {
                if (_pixelInCircle(px, py, x, y, radius)) {
                    setPixelColour(pixelData, colour, px, py);
                }
            }
        }
    }
}

// Draws a Circle outline on the bitmap
void drawCircleOutline(unsigned char *pixelData, int colour, int x, int y, int radius) {
    for (int px = x - radius; px < x + radius; ++px) {
        for (int py = y - radius; py < y + radius; ++py) {
            if (_pixelOnBitmap(px, py)) {
                if (_pixelInCircle(px, py, x, y, radius)) {
                    if (_pixelInCircle(px, py, x, y, radius - 1)) {
                        continue;
                    }
                    setPixelColour(pixelData, colour, px, py);
                }
            }
        }
    }
}

// Draws a filled in Triangle on the bitmap
void drawTriangleFilled(unsigned char *pixelData, int colour, int x1, int y1, int x2, int y2, int x3, int y3) {
    // create small arrays to find the min and max x and y values of the triangle
    // (this avoids iterating over the entire bitmap)
    int x[] = {x1, x2, x3};
    int y[] = {y1, y2, y3};
    for (int px = _min(x, 3); px < _max(x, 3) + 1; ++px) {
        for (int py = _min(y, 3); py < _max(y, 3) + 1; ++py) {
            if (_pixelOnBitmap(px, py)) {
                if (_pixelInTriangle(px, py, x1, y1, x2, y2, x3, y3)) {
                    setPixelColour(pixelData, colour, px, py);
                }
            }
        }
    }
}

// Draws a Triangle outline on the bitmap
void drawTriangleOutline(unsigned char *pixelData, int colour, int x1, int y1, int x2, int y2, int x3, int y3) {
    // draws 3 lines between each point
    drawLine(pixelData, colour, x1, y1, x2, y2);
    drawLine(pixelData, colour, x2, y2, x3, y3);
    drawLine(pixelData, colour, x3, y3, x1, y1);
}

// draws a line from (x1, y1) to (x2, y2)
void drawLine(unsigned char *pixelData, int colour, int x1, int y1, int x2, int y2) {
    int dx, dy, p, x, y;

    int xi = x1 < x2 ? 1 : -1;
    int yi = y1 < y2 ? 1 : -1;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    x = x1;
    y = y1;

    if (dx > dy) {  // low
        p = 2 * dy - dx;

        if (x2 < x1) {
            while (x >= x2) {
                if (_pixelOnBitmap(x, y)) {
                    setPixelColour(pixelData, colour, x, y);
                }
                if (p > 0) {
                    y += yi;
                    p += 2 * (dy - dx);
                } else {
                    p += 2 * dy;
                }
                x += xi;
            }
        } else {
            while (x <= x2) {
                if (_pixelOnBitmap(x, y)) {
                    setPixelColour(pixelData, colour, x, y);
                }
                if (p > 0) {
                    y += yi;
                    p += 2 * (dy - dx);
                } else {
                    p += 2 * dy;
                }
                x += xi;
            }
        }
    } else {  // high
        p = 2 * dx - dy;
        if (y2 < y1) {
            while (y >= y2) {
                if (_pixelOnBitmap(x, y)) {
                    setPixelColour(pixelData, colour, x, y);
                }
                if (p > 0) {
                    x += xi;
                    p += 2 * (dx - dy);
                } else {
                    p += 2 * dx;
                }
                y += yi;
            }
        } else {
            while (y <= y2) {
                if (_pixelOnBitmap(x, y)) {
                    setPixelColour(pixelData, colour, x, y);
                }
                if (p > 0) {
                    x += xi;
                    p += 2 * (dx - dy);
                } else {
                    p += 2 * dx;
                }
                y += yi;
            }
        }
    }
}

// *********************************
// ******* private functions *******
// * (not accessible in bmpCreate) *
// *********************************

// checks if pixel is on bitmap
int _pixelOnBitmap(int x, int y) {
    if (x >= 0 && x < IMG_WIDTH && y >= 0 && y < IMG_HEIGHT) {
        return TRUE;
    }
    return FALSE;
}

// checks if pixel is in circle
int _pixelInCircle(int x, int y, int centreX, int centreY, int radius) {
    int dx = abs(centreX - x);
    int dy = abs(centreY - y);
    if (dx * dx + dy * dy < (radius * radius)) {
        return TRUE;
    }
    return FALSE;
}

// Check if pixel is inside triangle
int _pixelInTriangle(int px, int py, int x1, int y1, int x2, int y2, int x3, int y3) {
    // get barycentric values
    float alpha = ((y2 - y3) * (px - x3) + (x3 - x2) * (py - y3)) / (float)((y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3));
    float beta = ((y3 - y1) * (px - x3) + (x1 - x3) * (py - y3)) / (float)((y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3));
    float gamma = 1.0F - alpha - beta;

    // if all barycentric values are greater than 0, then the point (px, py) is inside the triangle
    // using -0.001 for gamma to get a better triangle
    if (alpha >= 0.0F && beta >= 0.0F && gamma >= -0.001F) {
        return TRUE;
    }
    return FALSE;
}

// get min value in array
int _min(int *values, int size) {
    int min = values[0];
    for (int i = 1; i < size; i++) {
        if (values[i] < min) {
            min = values[i];
        }
    }
    return min;
}

// get max value
int _max(int *values, int size) {
    int max = values[0];
    for (int i = 1; i < size; i++) {
        if (values[i] > max) {
            max = values[i];
        }
    }
    return max;
}
