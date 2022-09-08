// A program to create a bitmap image (.bmp file)
// <the date here> <your name here>

#include <stdio.h>
#include <string.h>

#include "bmpShapeDrawing.h"

// List of Colours - used in 'setPixelColour' - (you can add your own too!)
#define WHITE 0
#define BLACK 1
#define GREY 2
#define RED 3
#define ORANGE 4
#define YELLOW 5
#define GREEN 6
#define BLUE 7
#define PURPLE 8
#define PINK 9

void setPixelRGB(unsigned char *pixelData, int x, int y, unsigned char r, unsigned char g, unsigned char b);
void setPixelColour(unsigned char *pixelData, int colour, int x, int y);
void testBitmap(unsigned char *pixelData);

int main(int argc, char *argv[]) {
    // This is the hex header that begins the bitmap
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

    // Every value is initialised to zero, so you will see a black square.
    unsigned char pixelData[IMG_WIDTH * PIXEL_SIZE * IMG_HEIGHT] = {0};

    // function call to create image matching Activity notes
    testBitmap(pixelData);

    // write data to .bmp file
    FILE *bmpFile = fopen("myBitmap.bmp", "wb");
    fwrite(bmpHeader, 1, 54, bmpFile);
    fwrite(pixelData, 1, sizeof(pixelData), bmpFile);
    char secretMessage[] = "[we don't talk about bruno]";
    fclose(bmpFile);

    return EXIT_SUCCESS;
}

// Sets the RGB (red, green, blue) values of pixel at (x, y) on bitmap
void setPixelRGB(unsigned char *pixelData, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    // TODO:
    // 1. Reverse y to start at top of bitmap image
    //    Hint: you can use the IMG_HEIGHT constant
    y = (?) - 1;

    // 2. calculate the pixel index on bitmap image and store in 'p'
    //    Hint: you can use the ROW_STRIDE and PIXEL_SIZE constants

    int p = y * (?) + x * (?);

    // 3. Assign the r (Red), g (Green), and b (Blue) parameters to the pixelData elements below
    pixelData[p + 0] = ? ;
    pixelData[p + 1] = ? ;
    pixelData[p + 2] = ? ;
}

// Sets the colour of pixel at (x, y) on bitmap
// 'colour' parameter uses value associated with #defines
void setPixelColour(unsigned char *pixelData, int colour, int x, int y) {
    if (colour == WHITE) {
        setPixelRGB(pixelData, x, y, 255, 255, 255);  // hex: (0xFF, 0xFF, 0xFF)
    } else if (colour == BLACK) {
        setPixelRGB(pixelData, x, y, 0, 0, 0);  // hex: (0x00, 0x00, 0x00)
    } else if (colour == GREY) {
        setPixelRGB(pixelData, x, y, 128, 128, 128);  // hex: (0x80, 0x80, 0x80)
    } else if (colour == RED) {
        setPixelRGB(pixelData, x, y, 255, 20, 20);  // hex: (0xFF, 0x14, 0x14)
    } else if (colour == ORANGE) {
        setPixelRGB(pixelData, x, y, 255, 100, 0);  // hex: (0xFF, 0x64, 0x00)
    } else if (colour == YELLOW) {
        setPixelRGB(pixelData, x, y, 255, 200, 0);  // hex: (0xFF, 0xC8, 0x00)
    } else if (colour == GREEN) {
        setPixelRGB(pixelData, x, y, 50, 200, 50);  // hex: (0x32, 0xC8, 0x32)
    } else if (colour == BLUE) {
        setPixelRGB(pixelData, x, y, 50, 100, 255);  // hex: (0x32, 0x64, 0xFF)
    } else if (colour == PURPLE) {
        setPixelRGB(pixelData, x, y, 120, 0, 255);  // hex: (0x78, 0x00, 0xFF)
    } else if (colour == PINK) {
        setPixelRGB(pixelData, x, y, 255, 80, 170);  // hex: (0xFF, 0x50, 0xAA)
    }
}

// function to test creating a bitmap - image should match Activity notes
void testBitmap(unsigned char *pixelData) {
    drawRectangleFilled(pixelData, RED, 0, 0, 170, 170);
    drawRectangleFilled(pixelData, ORANGE, 170, 0, 172, 170);
    drawRectangleFilled(pixelData, YELLOW, 342, 0, 170, 170);
    drawRectangleFilled(pixelData, GREEN, 342, 170, 170, 172);
    drawRectangleFilled(pixelData, BLUE, 342, 342, 170, 170);
    drawRectangleFilled(pixelData, PURPLE, 170, 342, 172, 170);
    drawRectangleFilled(pixelData, PINK, 0, 342, 170, 170);
    drawRectangleFilled(pixelData, GREY, 0, 170, 170, 172);
    drawRectangleFilled(pixelData, BLACK, 170, 170, 172, 172);
}
