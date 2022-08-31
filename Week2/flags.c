/*
 * 2.3 Functions to print text in color on unix terminal
 *
 * Written by Tony Caelum on 31/08/2023
 */

#include <stdlib.h>
#include <stdio.h>

#include "terminalColors.h"

int main (int argc, char *argv[]) {
    setBackgroundColor(0, 255, 0);
    printf("      ");
    setBackgroundColor(255, 255, 255);
    printf("      ");
    setBackgroundColor(255, 0, 0);
    printf("      ");
    resetTextColors();
    printf("\n");
    
    setBackgroundColor(0, 255, 0);
    printf("      ");
    setBackgroundColor(255, 255, 255);
    printf("      ");
    setBackgroundColor(255, 0, 0);
    printf("      ");
    resetTextColors();
    printf("\n");
    
    setBackgroundColor(0, 255, 0);
    printf("      ");
    setBackgroundColor(255, 255, 255);
    printf("      ");
    setBackgroundColor(255, 0, 0);
    printf("      ");
    resetTextColors();
    printf("\n");
    
    setBackgroundColor(0, 255, 0);
    printf("      ");
    setBackgroundColor(255, 255, 255);
    printf("      ");
    setBackgroundColor(255, 0, 0);
    printf("      ");
    resetTextColors();
    printf("\n");
    
    setBackgroundColor(0, 255, 0);
    printf("      ");
    setBackgroundColor(255, 255, 255);
    printf("      ");
    setBackgroundColor(255, 0, 0);
    printf("      ");
    resetTextColors();
    printf("\n");

    printf("\nlavoro fantastico!\n");

    return EXIT_SUCCESS;
}