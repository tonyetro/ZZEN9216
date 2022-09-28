/**
 *  This file contains the Mandelbrot functions and creates the image
 *  of the Mandelbrot Set and sent to a browser via localhost server.
 *
 *  Written by Tony Caelum on 15/19/22
 *
 *  Starter code written by Alli Murray on 19/04/22.
 *  Containing code created by Tim Lambert on 02/04/12
 *  and Richard Buckland on 28/01/11.
 *  Copyright 2012 Licensed under Creative Commons SA-BY-NC 3.0.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#include "mandelbrot.h"
#include "pixelColor.h"

// Image size constants
#define IMG_WIDTH 512
#define IMG_HEIGHT 512
#define HALF (IMG_WIDTH / 2) // keep a half value to reference
// Pixel reference constants
#define PIXEL_SIZE 3         // consistent with 3 values: R, G and B
#define ROW_STRIDE (IMG_WIDTH * PIXEL_SIZE)
// Escape steps maximum constant
#define MAX_STEPS 256

typedef struct complexNumber ComplexNumber;

struct complexNumber {
    double realComp;
    double imaginaryComp;
};

void printMandelbrot(unsigned char *pixelData,
                     double xCoor, double yCoor, int zoom);
int escapeSteps(double x, double y);
ComplexNumber mandelbrotAdd(ComplexNumber c1, ComplexNumber c2);
ComplexNumber mandelbrotSquare(ComplexNumber c);
double mandelbrotMagnitude(ComplexNumber c);

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
        0x36, 0x00, 0x0C, 0x00,  // bitmap file size
        0x00, 0x00,              // reserved 1 (must be 0)
        0x00, 0x00,              // reserved 2 (must be 0)
        0x36, 0x00, 0x00, 0x00,  // offset (in bytes)
        // BITMAPINFOHEADER
        0x28, 0x00, 0x00, 0x00,  // bitmap infor size
        0x00, 0x02, 0x00, 0x00,  // width of bitmap
        0x00, 0x02, 0x00, 0x00,  // height of bitmap
        0x01, 0x00,              // number of planes (1)
        0x18, 0x00,              // bit depth
        0x00, 0x00, 0x00, 0x00,  // compression type
        0x00, 0x00, 0x0C, 0x00,  // image size
        0x00, 0x00, 0x00, 0x00,  // horizontal res
        0x00, 0x00, 0x00, 0x00,  // vertical res
        0x00, 0x00, 0x00, 0x00,  // colours used
        0x00, 0x00, 0x00, 0x00   // important colours
    };
    write(socket, bmpHeader, sizeof(bmpHeader));

    // 1-D array to store all pixel RGB values
    unsigned char pixelData[ROW_STRIDE * IMG_HEIGHT] = {0};

    // Main driver - coordinates passed in and zoom level determine the
    // coming math calculations
    printMandelbrot(pixelData, xCoor, yCoor, zoom);

    // Write print BMP data to localhost via socket
    write(socket, pixelData, sizeof(pixelData));
}

void printMandelbrot(unsigned char *pixelData, double xCoor, double yCoor, int zoom) {
    double pixelDistance = pow(2, -zoom);
    int col, row = -HALF; // initialise col, set row to half IMG_WIDTH
    int p = 0; // p should start at zero and increase each iteration

    // Start bottom-left most point, working right and upwards towards
    // the top-left corner
    // Outer while loop: print in columns (image height)
    while (row < HALF) {
        col = -HALF;
        // Inner while loop: print in rows (image width)
        while (col < HALF) {
            // Calculate how many steps required at each point to
            // escape according to mandelbrot algorithm
            int result = escapeSteps(
                (col * pixelDistance) + xCoor,
                (row * pixelDistance) + yCoor);

            /**
             * With how many steps are required to escape, the less
             * steps required have higher RGB values and vice versa
             * NOTE: (MAX_STEPS - 1) is required as incrementation
             * always adds 1 before returning
             */
            if (result < MAX_STEPS) {
                pixelData[p + 0] = (MAX_STEPS - 1) - result;
                pixelData[p + 1] = (MAX_STEPS - 1) - result;
                pixelData[p + 2] = (MAX_STEPS - 1) - result;
            } else {
                pixelData[p + 0] = 0;
                pixelData[p + 1] = 0;
                pixelData[p + 2] = 0;
            }

            // When RGB values set, jump array by 1 pixel size
            p = p + PIXEL_SIZE;
            col = col + 1;
        }
        row = row + 1;
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

    return cplxNum;
}

ComplexNumber mandelbrotSquare(ComplexNumber c) {
    ComplexNumber cplxNum;
    cplxNum.realComp = pow(c.realComp, 2) - pow(c.imaginaryComp, 2);
    cplxNum.imaginaryComp = 2 * c.realComp * c.imaginaryComp;

    return cplxNum;
}

double mandelbrotMagnitude(ComplexNumber c) {
    return sqrt(pow(c.realComp, 2) + pow(c.imaginaryComp, 2));
}
