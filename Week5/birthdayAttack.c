#include "hashString.h"

char *hashBuilder(char *str, int attempt);
void printLogic(char *newValue, char *targetHash,
                int *mainCounter, int *matchCounter);

int main(void) {
    int mainCounter = 0, matchCounter = 1;
    char *targetHash = hash_string("z5411839 trollolololol", "sha1");

    while (mainCounter < MAX_ATTEMPTS && matchCounter <= MAX_MATCHES) {
        char zId[256] = "z5411839";
        char *newValue = hashBuilder(zId, mainCounter);
        
        // Rewrite attempt count. Resets 
        printf("\rAttempt:\t%d", mainCounter);
        fflush(stdout);

        // Pass in necessary params to print out correct matches 
        printLogic(newValue, targetHash,
                   &mainCounter, &matchCounter);

        mainCounter = mainCounter + 1;
    }
}

char *hashBuilder(char *zId, int attempt) {
    char result[] = " 0000000";
    sprintf(result, " %07d", attempt);
    strcat(zId, result);

    return zId;
}

void printLogic(char *newValue, char *targetHash,
                int *mainCounter, int *matchCounter) {
    char *newHash = hash_string(newValue, "sha1");
    // If match counter is successful, print hashes and
    // reset match counter until it maxes out
    if (strncmp(newHash, targetHash, *matchCounter) == 0) {
        if (*matchCounter == 1) {
            printf("\nMatch for %d character:\n", *matchCounter);
        } else {
            printf("\nMatch for %d characters:\n", *matchCounter);
        }
        printf("Value:\t%s\n"
               "Hash:\t%s\n\n",
               newValue, newHash);

        *mainCounter = 0;

        if (*matchCounter == MAX_MATCHES) {
            *mainCounter = MAX_ATTEMPTS; // Escape all looping
        } else {
            *matchCounter = *matchCounter + 1;
        }
    } else if (*mainCounter + 1 == MAX_ATTEMPTS) {
        printf("No match found.");
    }
}
