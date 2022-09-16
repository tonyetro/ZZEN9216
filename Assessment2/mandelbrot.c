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

// TODO: Write your #defines here.

struct complexNumber {
    // TODO: Fill out the struct using your Activity 3.3 solution.
};

// TODO: Add your function prototypes here.

void serveBMP (int socket, double xCoor, double yCoor, int zoom) {
    char* message;

    // First send the http response header.

    // (If you write stings one after another like this on separate
    // lines the c compiler kindly joins them togther for you into
    // one long string)
    message = "HTTP/1.0 200 OK\r\n"
              "Content-Type: image/bmp\r\n"
              "\r\n";
    write (socket, message, strlen (message));

    // This is the hex header that begins the bitmap.
    char bmpHeader[] = {
        0x42,0x4D,0x36,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x36,0x00,
        0x00,0x00,0x28,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x02,
        0x00,0x00,0x01,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00
    };
    write (socket, bmpHeader, sizeof(bmpHeader));

    // TODO: Write your code here to create and serve the bmp image.

    // If you completed Part 2 (asterisk.c), add your printMandelbrot
    // code here and adapt it to work with pixels.
}

// TODO: Add your Mandelbrot Functions from Activity 3.3 here.
