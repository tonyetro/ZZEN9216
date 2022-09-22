/**
 * Tony Caleum
 * 19 September 22, ZZEN9216
 * Driver function to increment a counter, run through a hashing
 * function then comparing the first four chacters to the hash
 * of my student number (z5411839)
 */

#include "hash_string.h"

int main(void) {
    int counter = 0;
    char *currentHash;
    // generate a SHA1 hash of your zID
    char *target_hash = hash_string("z5411839", "sha1");
    printf("The SHA1 hash of my zID is %s\n", target_hash);

    while (counter < MAX_ATTEMPTS) {
        // store counter int as a string with a SHA-1 compliant buffer
        snprintf(currentHash, 40, "%d", counter);
        // generate a new hash and reuse variable
        currentHash = hash_string(currentHash, "sha1");

        printf("Attempt %d of %d: %s\n", counter, MAX_ATTEMPTS, currentHash);

        // compare it to the original (first four characters)
        if (strncmp(currentHash, target_hash, 4) == 0) {
            printf("\nWe have a partial match:\nCurrent hash:\t%s\nOriginal hash:\t%s\n\n", currentHash, target_hash);
            counter = MAX_ATTEMPTS; // Escape while loop
        } else if (counter + 1 == MAX_ATTEMPTS) {
            printf("No match found.");
        }

        counter = counter + 1;
    }

    return 0;
}
