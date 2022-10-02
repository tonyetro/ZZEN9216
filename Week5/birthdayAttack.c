#include "hashString.h"

#define MAX_ATTEMPTS 9999999 // max unsigned int
#define MAX_MATCHES 6

char *hashBuilder(char *str, int attempt);
void printLogic(char *newValue, char *targetValue, char *targetHash,
                int *mainCounter, int *matchCounter);
void printToDisk(char *valueOne, char *valueTwo);

int main(void) {
    int mainCounter = 0, matchCounter = 1;
    char *targetValue = "z5411839 trololololol";
    char *targetHash = hashString(targetValue, "sha1");

    while (mainCounter < MAX_ATTEMPTS && matchCounter <= MAX_MATCHES) {
        char zId[256] = "z5411839";
        char *newValue = hashBuilder(zId, mainCounter);
        
        // Rewrite attempt count. Resets 
        printf("\rAttempt:\t%d", mainCounter);
        fflush(stdout);

        // Pass in necessary params to print out correct matches 
        printLogic(newValue, targetValue, targetHash,
                   &mainCounter, &matchCounter);

        mainCounter = mainCounter + 1;
    }
}

char *hashBuilder(char *zId, int attempt) {
    char result[] = " 00000000";
    sprintf(result, " %08d", attempt);
    strcat(zId, result);
    return zId;
}

void printLogic(char *newValue, char *targetValue, char *targetHash,
                int *mainCounter, int *matchCounter) {
    char *newHash = hashString(newValue, "sha1");

    // If match counter is successful, print hashes and
    // reset match counter until it maxes out
    if (strncmp(newHash, targetHash, *matchCounter) == 0) {
        if (*matchCounter == 1) {
            printf("\nResult for %d matching character:\n", *matchCounter);
        } else {
            printf("\nResult for %d matching characters:\n", *matchCounter);
        }

        printf("Target Hash:\t%s | Value: %s\n"
               "Found Hash:\t%s | Value: %s\n\n",
               targetHash, targetValue, newHash, newValue);

        if (*matchCounter == MAX_MATCHES) {
            // With final result, write to files on disk:
            // input_1.txt and input_2.txt
            printToDisk(newValue, targetValue);
            
            // Escape all loops and eventually the program
            *mainCounter = MAX_ATTEMPTS; // Escape all looping
        } else {
            *matchCounter = *matchCounter + 1;
        }
    } else if (*mainCounter + 1 == MAX_ATTEMPTS) {
        printf("No match found.");
    }
}

void printToDisk(char *valueOne, char *valueTwo) {
    FILE *inputFilePtrOne = fopen("input_1.txt", "w");
    fprintf(inputFilePtrOne, "%s", valueOne);
    fclose(inputFilePtrOne);
    
    FILE *inputFilePtrTwo = fopen("input_2.txt", "w");
    fprintf(inputFilePtrTwo, "%s", valueTwo);
    fclose(inputFilePtrTwo);
}
