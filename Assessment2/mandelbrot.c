/*
 *  This file contains the Mandelbrot functions and creates the
 *  image of the Mandelbrot Set.
 *
 *  Written by <your-name-here> on dd/mm/yy
 *
 *  Starter code written by Alli Murray on 19/04/22.
 *  Containing code created by Tim Lambert on 02/04/12
 *  and Richard Buckland on 28/01/11.
 *  Copyright 2012 Licensed under Creative Commons SA-BY-NC 3.0.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#include "mandelbrot.h"
#include "pixelColor.h"

#define IMG_WIDTH 512
#define IMG_HEIGHT 512
#define PIXEL_SIZE 3
#define ROW_STRIDE (IMG_WIDTH * PIXEL_SIZE)

#define MAX_STEPS 256

typedef struct complexNumber ComplexNumber;

struct complexNumber {
    double realComp;
    double imaginaryComp;
};

ComplexNumber mandelbrotAdd(ComplexNumber c1,
                            ComplexNumber c2);
ComplexNumber mandelbrotSquare(ComplexNumber c);
double mandelbrotMagnitude(ComplexNumber c);
void printMandelbrot(unsigned char *pixelData, double xCoor, double yCoor, int zoom);
int escapeSteps(double x, double y);

void setPixelRGB(unsigned char *pixelData,
                 int x, int y,
                 unsigned char r, unsigned char g, unsigned char b);

void serveBMP(int socket, double xCoor, double yCoor, int zoom) {
    char* message;

    // First send the http response header.

    // (If you write stings one after another like this on separate
    // lines the c compiler kindly joins them togther for you into
    // one long string)
    message = "HTTP/1.0 200 OK\r\n"
              "Content-Type: image/bmp\r\n"
              "\r\n";
    write(socket, message, strlen(message));

    // This is the hex header that begins the bitmap.
    char bmpHeader[] = {
        // BITMAPFILEHEADER
        0x42, 0x4D,              // file type ("BM")
        0x36, 0x00, 0x0C, 0x00,  // bitmap file size (in bytes)
        0x00, 0x00,              // reserved 1 (must be 0)
        0x00, 0x00,              // reserved 2 (must be 0)
        0x36, 0x00, 0x00, 0x00,  // offset (in bytes) for where pixel data starts (54)
        // BITMAPINFOHEADER
        0x28, 0x00, 0x00, 0x00,  // bitmap information size (in bytes) (40)
        0x00, 0x02, 0x00, 0x00,  // width of bitmap (in pixels)
        0x00, 0x02, 0x00, 0x00,  // height of bitmap (in pixels)
        0x01, 0x00,              // number of planes (1)
        0x18, 0x00,              // bit depth (24 for 24-bit bitmap)
        0x00, 0x00, 0x00, 0x00,  // type of compression (0 for uncompressed bitmaps)
        0x00, 0x00, 0x0C, 0x00,  // image size (IMG_WIDTH * PIXEL_SIZE * IMG_HEIGHT)
        0x00, 0x00, 0x00, 0x00,  // horizontal resolution (can be ignored)
        0x00, 0x00, 0x00, 0x00,  // vertical resolution (can be ignored)
        0x00, 0x00, 0x00, 0x00,  // colours used (0 = max for bit depth used)
        0x00, 0x00, 0x00, 0x00   // important colours (0 = all colours required)
    };
    write(socket, bmpHeader, sizeof(bmpHeader));

    // TODO: Write your code here to create and serve the bmp image.

    // If you completed Part 2 (asterisk.c), add your printMandelbrot
    // code here and adapt it to work with pixels.
    unsigned char pixelData[ROW_STRIDE * IMG_HEIGHT] = {0};

    printMandelbrot(pixelData, xCoor, yCoor, zoom);

    write(socket, pixelData, sizeof(pixelData));
}

void printMandelbrot(unsigned char *pixelData, double xCoor, double yCoor, int zoom) {
    double pixelDistance = pow(2, -zoom);
    int half = IMG_HEIGHT / 2;
    int row = half;
    int col = -half;

    int p = (yCoor * ROW_STRIDE) + (xCoor * PIXEL_SIZE);

    // code to print in columns
    while (row > -half) {
        col = -half;
        // code to print in rows
        while (col < half) {
            int result = escapeSteps(
                (col * pixelDistance) + xCoor,
                (row * pixelDistance) + yCoor);

            if (result < MAX_STEPS) {
                pixelData[p + 0] = -result;
                pixelData[p + 1] = -result;
                pixelData[p + 2] = -result;
            }

            p = p + PIXEL_SIZE;
            col = col + 1;
        }
        row = row - 1;
    }
}

int escapeSteps(double x, double y) {
    int counter = 0;
    double magnitude = 0;
    ComplexNumber originPoint, complexNum;
    originPoint.realComp = 0;
    originPoint.imaginaryComp = 0;
    complexNum.realComp = x;
    complexNum.imaginaryComp = y;

    // If within MAX_STEPS and magnitude is 2 or under
    while (counter < MAX_STEPS && magnitude <= 2) {
        originPoint = mandelbrotSquare(originPoint);
        originPoint = mandelbrotAdd(originPoint, complexNum);
        magnitude = mandelbrotMagnitude(originPoint);

        counter = counter + 1;
    }

    return counter;
}

ComplexNumber mandelbrotAdd(ComplexNumber c1,
                            ComplexNumber c2) {
    ComplexNumber cplxNum;
    cplxNum.realComp = c1.realComp + c2.realComp;
    cplxNum.imaginaryComp = c1.imaginaryComp + c2.imaginaryComp;
    // printf("\nADD 1 REAL: %g, ADD 1 IMAG: %g\nADD 2 REAL: %g, ADD 2 IMAG: %g\n", c1.realComp, c1.imaginaryComp, c2.realComp, c2.imaginaryComp);
    return cplxNum;
}

ComplexNumber mandelbrotSquare(ComplexNumber c) {
    ComplexNumber cplxNum;
    cplxNum.realComp = pow(c.realComp, 2) - pow(c.imaginaryComp, 2);
    cplxNum.imaginaryComp = 2 * c.realComp * c.imaginaryComp;
    // printf("\nSQUARE REAL: %g, SQUARE IMAG: %g\n", c.realComp, c.imaginaryComp);
    return cplxNum;
}

double mandelbrotMagnitude(ComplexNumber c) {
    return sqrt(pow(c.realComp, 2) + pow(c.imaginaryComp, 2));
    // printf("\n%g\n", sqrt(pow(c.realComp, 2) + pow(c.imaginaryComp, 2)));
}
