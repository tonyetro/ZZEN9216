#include "hashString.h"

char *hashBuilder(char *str, int attempt);

int main(void) {
    int counter = 0;

    while (counter < MAX_ITERATIONS) {
        printf("Iteration %d\n", counter);

        char zID[256] = "z5411839";
        char *newHash = hashBuilder(zID, counter);

        printf("newHash: %s\n", newHash);

        counter = counter + 1;
    }
}

char *hashBuilder(char *str, int attempt) {
    char result[] = " 0000000";
    sprintf(result, " %07d", attempt);
    strcat(str, result);

    return hash_string(str, "sha1");
}
