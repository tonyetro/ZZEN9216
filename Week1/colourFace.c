/*
 * Tony Caleum
 * 7 September 22, ZZEN9216
 * Adding colour to face from the previous exercise
 */

#include <stdio.h>

int main(void) {
    printf(
        "  \033[35m_         _    \n"
        " \033[37m/\033[34m^\033[37m\\       /\033[34m^\033[37m\\ \n"
        "\033[37m__    \033[33m.\033[31m^\033[33m.    \033[37m__  \n"
        "\033[36m\\/           \\/\n"
        " \033[31m\\\033[33m___________\033[31m/  \n"
    );
    return 0;
}
