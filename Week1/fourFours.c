/*
 * Tony Caelum
 * 30 August 22, ZZEN9216
 * Four 4's game written in C language, solutions 0-29
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

// change this to be you
#define MINE "Tony's"

int main (int arc, char *argv[]) {
    int sum0, sum1, sum2, sum3, sum4;
    int sum5, sum6, sum7, sum8, sum9;
    int sum10, sum11, sum12, sum13, sum14;
    int sum15, sum16, sum17, sum18, sum19;
    int sum20, sum21, sum22, sum23, sum24;
    int sum25, sum26, sum27, sum28, sum29;

    // solutions 0-9
    sum0 = (4 - 4) + (4 - 4);
    sum1 = (4 / 4) * (4 / 4);
    sum2 = (4 / 4) + (4 / 4);
    sum3 = (4 + 4 + 4) / 4;
    sum4 = 4 + (4 - 4) * 4;
    sum5 = (4 + 4 * 4) / 4;
    sum6 = (4 + 4) / 4 + 4;
    sum7 = (44 / 4) - 4;
    sum8 = (4 + 4) + (4 -4);
    sum9 = 4 + 4 + (4 / 4);

    // solutions 10-19
    sum10 = 4 + 4 + 4 - sqrt(4);
    sum11 = 44 / (sqrt(4) * sqrt(4));
    sum12 = 4 * (4 - (4/4));
    sum13 = (44 / 4) + sqrt(4);
    sum14 = 4 + 4 + 4 + sqrt(4);
    sum15 = (44 / 4) + 4;
    sum16 = 4 + 4 + 4 + 4;
    sum17 = (4 * 4) + (4 / 4);
    sum18 = (4 * 4) + 4 - sqrt(4);
    sum19 = (4 * 4) + (sqrt(4 / .4));

    sum20 = 4 * (4 + 4 / 4);
    sum21 = (4.4 + 4) / .4;
    sum22 = (44 / 4) * sqrt(4);
    sum23 = (44 + sqrt(4)) / sqrt(4);
    sum24 = 4 * 4 + 4 + 4;
    sum25 = (4 + 4 + sqrt(4)) / .4;
    sum26 = 4 / .4 + 4 * 4;
    sum27 = 44 / 4 / .4;
    sum28 = 44 - 4 * 4;
    sum29 = 4 / .4 / .4 + 4;

    printf(
        "Welcome to %s version of the Four Fours problem."
        "Here goes:\n", MINE
    );

    // sum0 ~ sum9
    printf(
        "%d - %d - %d - %d - %d ",
        sum0, sum1, sum2, sum3, sum4);
    printf(
        "%d - %d - %d - %d - %d\n",
        sum5, sum6, sum7, sum8, sum9
    );

    // test that the correct answers are being produced
    // test cases 0 ~ 9
    assert(sum0 == 0);
    assert(sum1 == 1);
    assert(sum2 == 2);
    assert(sum3 == 3);
    assert(sum4 == 4);
    assert(sum5 == 5);
    assert(sum6 == 6);
    assert(sum7 == 7);
    assert(sum8 == 8);
    assert(sum9 == 9);
    printf("All tests 0-9 passed! Well done. You are awesome!\n");

    // sum10 ~ sum19
    printf(
        "%d - %d - %d - %d - %d ",
        sum10, sum11, sum12, sum13, sum14
    );
    printf(
        "%d - %d - %d - %d - %d\n",
        sum15, sum16, sum17, sum18, sum19
    );

    // test cases 10 ~ 19
    assert(sum10 == 10);
    assert(sum11 == 11);
    assert(sum12 == 12);
    assert(sum13 == 13);
    assert(sum14 == 14);
    assert(sum15 == 15);
    assert(sum16 == 16);
    assert(sum17 == 17);
    assert(sum18 == 18);
    assert(sum19 == 19);
    printf("All tests 10-19 passed! Well done. You are awesome!\n");

    // sum20 ~ sum29
    printf(
        "%d - %d - %d - %d - %d ",
        sum20, sum21, sum22, sum23, sum24
    );
    printf(
        "%d - %d - %d - %d - %d\n",
        sum25, sum26, sum27, sum28, sum29
    );

    // test cases 20 ~ 29
    assert(sum20 == 20);
    assert(sum21 == 21);
    assert(sum22 == 22);
    assert(sum23 == 23);
    assert(sum24 == 24);
    assert(sum25 == 25);
    assert(sum26 == 26);
    assert(sum27 == 27);
    assert(sum28 == 28);
    assert(sum29 == 29);
    printf("All tests 20-29 passed! Well done. You are awesome!\n");

    return EXIT_SUCCESS;
}
