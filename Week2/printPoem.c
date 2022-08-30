/*
 * printPoem.c
 * Roses are red exercise across multiple files
 * Written by Tony Caelum on 30/08/2022
 */

#include <stdlib.h>
#include <stdio.h>

#include "terminalColors.h"

int main (int argc, char *argv[]) {
    setForegroundColor(203, 135, 164);
    printf("so much depends\n");

    setForegroundColor(237, 142, 164);
    printf("upon\n");

    setForegroundColor(255, 145, 128);
    printf("a red wheel\n");

    setForegroundColor(255, 167, 140);
    printf("barrow\n");

    setForegroundColor(255, 203, 135);
    printf("glazed with rain\n");

    setForegroundColor(255, 229, 158);
    printf("water\n");

    setForegroundColor(255, 244, 176);
    printf("beside the white\n");

    setForegroundColor(255, 254, 217);
    printf("chickens\n");

    setForegroundColor(245, 245, 245);
    printf("\nDone!\n");

    return EXIT_SUCCESS;
}
