// Find out if your machine uses little endian or big endian addressing
// 20 Jul 2022, Sascha Graham

#include <stdio.h>

int main() {

    // Store an integer i in 4 bytes of memory
    int i = 1;

    /**
    In a little endian system, i will be stored in memory like this:
    +----+----+----+----+
    |0x01|0x00|0x00|0x00|
    +----+----+----+----+
    |
    |
    &i

    Remember that "&i" refers to the "address of x" in memory.

    In a big endian system, i is stored like this:
    +----+----+----+----+
    |0x00|0x00|0x00|0x01|
    +----+----+----+----+
    |
    |
    &i

    Note that the order of the bytes is reversed.
    */

    // define a pointer to a char, c, to be the address of i
    char *c = (char*)&i;

    /*
    Whereas the size of an int is 4 bytes, the size of a char is only 1 byte.

    Our new char, c, is now a pointer to the first byte that i is stored in.

    In a little endian system, the value of that first byte is 1,
    while in a big endian system, the value is 0.
    */

    // Now we can check the value of the byte to find out which endianness our system has
    if (*c == 1) {
        printf("My machine is little endian\n");
    } else {
        printf("My machine is big endian\n");
    }
    return 0;
}
