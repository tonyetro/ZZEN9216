/**
 * Creating and writing to a new BMP file, adding a programmer joke
 * only viewable in a hexadecimal editor.
 * Written by Tony Caelum on 05/09/22
 */

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
    char secretMessage[] = "["
        "How many programmers does it take to change a light bulb?"
        "None - it's a hardware problem."
    "]";
    fwrite(secretMessage, 1, sizeof(secretMessage), bmpFile);
    fclose(bmpFile);

    return EXIT_SUCCESS;
}

// Sets the RGB (red, green, blue) values of pixel at (x, y) on bitmap
void setPixelRGB(unsigned char *pixelData,
    int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    // TODO:
    // 1. Reverse y to start at top of bitmap image
    //    Hint: you can use the IMG_HEIGHT constant
    y = IMG_HEIGHT - y - 1;

    // 2. calculate the pixel index on bitmap image and store in 'p'
    //    Hint: you can use the ROW_STRIDE and PIXEL_SIZE constants
    int p = y * ROW_STRIDE + x * PIXEL_SIZE;

    // 3. Assign the r (Red), g (Green), and b (Blue) parameters to the pixelData elements below
    pixelData[p + 0] = b;
    pixelData[p + 1] = g;
    pixelData[p + 2] = r;
}

// Sets the colour of pixel at (x, y) on bitmap
// 'colour' parameter uses value associated with #defines
void setPixelColour(unsigned char *pixelData, int colour, int x, int y) {
    if (colour == WHITE) {
        setPixelRGB(pixelData, x, y, 255, 255, 255);
    } else if (colour == BLACK) {
        setPixelRGB(pixelData, x, y, 0, 0, 0);
    } else if (colour == GREY) {
        setPixelRGB(pixelData, x, y, 128, 128, 128);
    } else if (colour == RED) {
        setPixelRGB(pixelData, x, y, 255, 20, 20);
    } else if (colour == ORANGE) {
        setPixelRGB(pixelData, x, y, 255, 100, 0);
    } else if (colour == YELLOW) {
        setPixelRGB(pixelData, x, y, 255, 200, 0);
    } else if (colour == GREEN) {
        setPixelRGB(pixelData, x, y, 50, 200, 50);
    } else if (colour == BLUE) {
        setPixelRGB(pixelData, x, y, 50, 100, 255);
    } else if (colour == PURPLE) {
        setPixelRGB(pixelData, x, y, 120, 0, 255);
    } else if (colour == PINK) {
        setPixelRGB(pixelData, x, y, 255, 80, 170);
    }
}

// function to test creating a bitmap - image should match Activity notes
void testBitmap(unsigned char *pixelData) {
    // Standard black background, just for preference
    drawBackground(pixelData, BLACK);

    /**
     * Create a background grid with a 2D array, overlaying background
     * Image size is set to 512x512, so havbe chosed 64x64 squares
     * with a grey-ish background rather than white for less contrast
     */
    int gridRow = 0, gridCol = 0;
    while (gridCol < 512) {
        while (gridRow < 512) {
            drawRectangleOutline(
                pixelData, GREY, gridRow, gridCol, 64, 64
            );
            gridRow = gridRow + 64;
        }
        gridRow = 0;
        gridCol = gridCol + 64;
    }

    /**
     * Draw circles within each other, with
     * black outline for practicing using templated functions
     * Note: In the pattern of "Sing a Rainbow" by Arthur Hamilton
     */
    drawCircleOutline(pixelData, BLACK, 256, 256, 231);
    drawCircleFilled(pixelData, RED, 256, 256, 230);
    drawCircleOutline(pixelData, BLACK, 256, 256, 201);
    drawCircleFilled(pixelData, YELLOW, 256, 256, 200);
    drawCircleOutline(pixelData, BLACK, 256, 256, 171);
    drawCircleFilled(pixelData, PINK, 256, 256, 170);
    drawCircleOutline(pixelData, BLACK, 256, 256, 141);
    drawCircleFilled(pixelData, GREEN, 256, 256, 140);
    drawCircleOutline(pixelData, BLACK, 256, 256, 111);
    drawCircleFilled(pixelData, PURPLE, 256, 256, 110);
    drawCircleOutline(pixelData, BLACK, 256, 256, 71);
    drawCircleFilled(pixelData, ORANGE, 256, 256, 70);
    drawCircleOutline(pixelData, BLACK, 256, 256, 41);
    drawCircleFilled(pixelData, BLUE, 256, 256, 40);

    /**
     * Draw random triangle to overlap the centre color
     * Then another outline, to practice drawing with an offset shape
     */
    drawTriangleFilled(pixelData, YELLOW,
        gridCol / 2, 202,
        gridCol / 2 - 45, 280,
        gridCol / 2 + 45, 280
    );

    drawTriangleOutline(pixelData, BLACK,
        gridCol / 2 + 5, 205,
        gridCol / 2 - 50, 275,
        gridCol / 2 + 45, 285
    );
}
