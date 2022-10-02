#include "hashString.h"

char *hashBuilder(char *str, int attempt);
void printLogic(char *newHash, char *targetHash,
                int *mainCounter, int *matchCounter, int maxMatches);

int main(void) {
    int mainCounter = 0;
    int matchCounter = 1, maxMatches = 4;
    char *targetHash = hash_string("z5411839", "sha1");

    while (mainCounter < MAX_ATTEMPTS && matchCounter <= maxMatches) {
        char zId[256] = "z5411839";
        char *newHash = hashBuilder(zId, mainCounter);
        
        // Rewrite attempt count. Resets 
        printf("\rAttempt:\t%d", mainCounter);
        fflush(stdout);

        // Pass in necessary params to print out correct matches 
        printLogic(newHash, targetHash,
                   &mainCounter, &matchCounter, maxMatches);
    
        mainCounter = mainCounter + 1;
    }
}

char *hashBuilder(char *str, int attempt) {
    char result[] = " 0000000";
    sprintf(result, " %07d", attempt);
    strcat(str, result);

    return hash_string(str, "sha1");
}

void printLogic(char *newHash, char *targetHash,
                int *mainCounter, int *matchCounter, int maxMatches) {
    // If match counter is successful, print hashes and
    // reset match counter until it maxes out
    if (strncmp(newHash, targetHash, *matchCounter) == 0) {
        if (*matchCounter == 1) {
            printf("\nMatch for %d character:\n", *matchCounter);
        } else {
            printf("\nMatch for %d characters:\n", *matchCounter);
        }
        printf("Current hash:\t%s\n"
               "Original hash:\t%s\n\n",
               newHash, targetHash);

        *matchCounter = *matchCounter + 1;
        *mainCounter = 0;

        if (*matchCounter == maxMatches) {
            *mainCounter = MAX_ATTEMPTS; // Escape all looping
        }
    } else if (*mainCounter + 1 == MAX_ATTEMPTS) {
        printf("No match found.");
    }
}
