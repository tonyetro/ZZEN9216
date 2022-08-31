// functions to print text in color on unix terminal
// 7 Feb 22 Richard Buckland

#include <stdlib.h>
#include <stdio.h>

#include "terminalColors.h"

int main (int argc, char *argv[]) {
    printf("\nTesting setForegroundColor()\n");
    setForegroundColor(255,0,0);
    printf("This should be RED\n");
    setForegroundColor(0,255,0);
    printf("This should be GREEN\n");
    setForegroundColor(0,0,255);
    printf("This should be BLUE\n");
    setForegroundColor(255,255,0);
    printf("This should be YELLOW\n");
    setForegroundColor(0,255,255);
    printf("This should be AQUA\n");
    setForegroundColor(255,0,255);
    printf("This should be PURPLE\n");
    setForegroundColor(100,100,100);
    printf("This should be GREY\n");
    setForegroundColor(255,255,255);
    printf("This should be WHITE\n");
    
    printf("\n\nTesting setBackgroundColor()\n");
    setBackgroundColor(255,0,0);
    printf("Background should be RED\n");
    setBackgroundColor(0,255,0);
    printf("Background should be GREEN\n");
    setBackgroundColor(0,0,255);
    printf("Background should be BLUE\n");
    setBackgroundColor(255,255,0);
    printf("Background should be YELLOW\n");
    setBackgroundColor(0,255,255);
    printf("Background should be AQUA\n");
    setBackgroundColor(255,0,255);
    printf("Background should be PURPLE\n");
    setBackgroundColor(100,100,100);
    printf("Background should be GREY\n");
    
    // new lines seem to colour everything below the line being 
    // printed too. So set to black before  printing each newline.
    setBackgroundColor(0,0,0);
    printf("\n");
    printf("\n\nTesting setBackgroundColor() with black resets\n");
    setBackgroundColor(255,0,0);
    printf("Background should be RED");
    setBackgroundColor(0,0,0);  // reset everything below to be black
    printf("\n");
    setBackgroundColor(0,255,0);
    printf("Background should be GREEN");
    setBackgroundColor(0,0,0);  // reset everything below to be black
    printf("\n");
    setBackgroundColor(0,0,255);
    printf("Background should be BLUE");
    setBackgroundColor(0,0,0);  // reset everything below to be black
    printf("\n");
    setBackgroundColor(255,255,0);
    printf("Background should be YELLOW");
    setBackgroundColor(0,0,0);  // reset everything below to be black
    printf("\n");
    setBackgroundColor(0,255,255);
    printf("Background should be AQUA");
    setBackgroundColor(0,0,0);  // reset everything below to be black
    printf("\n");
    setBackgroundColor(255,0,255);
    printf("Background should be PURPLE");
    setBackgroundColor(0,0,0);  // reset everything below to be black
    printf("\n");
    setBackgroundColor(100,100,100);
    printf("Background should be GREY");
    setBackgroundColor(0,0,0);  // reset everything below to be black
    printf("\n");
    
    printf ("\nDone!\n");
 
    return EXIT_SUCCESS;
}