/**
 * Tony Caleum
 * 19 September 22, ZZEN9216
 */

// write input to a temp file,
// generate the hash of the file using the specified method,
// delete the file
// return the hash

#define TMP_FILENAME "HASH_STRING_TMP.txt"
#define MAX_ATTEMPTS 200000

#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

char *hash_string(char *toHash, char *method) {
    unsigned char buffer[BUFSIZ];
    FILE *f;
    size_t len;

    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    unsigned char md_value[EVP_MAX_MD_SIZE];
    unsigned int md_len;
    unsigned int i;

    // check the specified hash method is valid
    // drop an error if it isn't
    md = EVP_get_digestbyname(method);
    if (md == NULL) {
        printf("Error: unknown hash method: %s\n", method);
        exit(1);
    }

    // create a tmp file to contain the inputted string
    f = fopen(TMP_FILENAME, "w+");
    if (f == NULL) {
        fprintf(stderr, "Couldn't open tmp file for hashing!\n");
        exit(1);
    }

    // write the input string to file
    fputs(toHash, f);
    rewind(f);

    // compute the hash
    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);

    do {
        len = fread(buffer, 1, BUFSIZ, f);
        EVP_DigestUpdate(mdctx, buffer, len);
    } while (len == BUFSIZ);

    EVP_DigestFinal_ex(mdctx, md_value, &md_len);
    EVP_MD_CTX_free(mdctx);

    // format hash from hex to string
    char *hash_as_string = malloc(sizeof(char) * md_len*2 + 1);
    for (i = 0; i < md_len; i++) {
        sprintf(&hash_as_string[i*2], "%02x", md_value[i]);
    }

    // close and delete the tmp file
    fclose(f);
    if (!remove(TMP_FILENAME) == 0) {
        printf("Error: tmp file couldn't be deleted\n");
    }

    EVP_cleanup();

    return hash_as_string;
}
