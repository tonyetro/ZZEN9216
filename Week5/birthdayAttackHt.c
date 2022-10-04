/**
 * Tony Caleum
 * Hashes and compares my zID with a randomness concatenated
 * Then hashes and compares 1~6 characters and the beginning of each
 * 30 September 22, ZZEN9216
 */

#include "hashString.h"

#define MAX_ATTEMPTS 9999999 // max unsigned int
#define MAX_MATCHES 6
#define CAPACITY 20 // Size of the Hash Table

unsigned long hash_function(char* str) {
    unsigned long i = 0;

    for (int j = 0; str[j]; j++)
        i += str[j];

    return i % CAPACITY;
}

typedef struct Ht_item Ht_item;

// Define the Hash Table Item here
struct Ht_item {
    char* key;
    char* value;
};

typedef struct HashTable HashTable;

// Define the Hash Table here
struct HashTable {
    // Contains an array of pointers to items
    Ht_item** items;
    int size;
    int count;
};

Ht_item* create_item(char* key, char* value);
HashTable* create_table(int size);
void free_item(Ht_item* item);
void free_table(HashTable* table);
void ht_insert(HashTable* table, char* key, char* value);
char* ht_search(HashTable* table, char* key);
void print_search(HashTable* table, char* key);
void print_table(HashTable* table);

char *hashBuilder(char *str, int attempt);
void printLogic(char *newValue, char *targetValue, char *targetHash,
                int *mainCounter, int *matchCounter);
void printToDisk(char *valueOne, char *valueTwo);

int main(void) {
    int mainCounter = 0;//, matchCounter = 1;
    // char *targetValue = "z5411839 trololololol";
    // char *targetHash = hashString(targetValue, "sha1");
    HashTable* ht = create_table(CAPACITY);

    // while (mainCounter < MAX_ATTEMPTS && matchCounter <= MAX_MATCHES) {
    while (mainCounter < CAPACITY) {
        char zId[256] = "z5411839";
        char *newValue = hashBuilder(zId, mainCounter);

        // Rewrite attempt count. Resets
        printf("\rAttempt:\t%d", mainCounter);
        fflush(stdout);

        char res[] = "00000000";
        sprintf(res, "%d", mainCounter);
        ht_insert(ht, res, newValue);

        // Pass in necessary params to print out correct matches
        // printLogic(newValue, targetValue, targetHash,
        //            &mainCounter, &matchCounter);

        mainCounter = mainCounter + 1;
    }

    // ht_search(ht, mainCounter);
    print_table(ht);
    free_table(ht);
    return 0;
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
            printf("\nResult for %d matching character:\n",
                   *matchCounter);
        } else {
            printf("\nResult for %d matching characters:\n",
                   *matchCounter);
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

Ht_item* create_item(char* key, char* value) {
    // Creates a pointer to a new hash table item
    Ht_item* item = (Ht_item*) malloc (sizeof(Ht_item));
    item->key = (char*) malloc (strlen(key) + 1);
    item->value = (char*) malloc (strlen(value) + 1);

    strcpy(item->key, key);
    strcpy(item->value, value);

    return item;
}

HashTable* create_table(int size) {
    // Creates a new HashTable
    HashTable* table = (HashTable*) malloc (sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (Ht_item**) calloc (table->size, sizeof(Ht_item*));
    for (int i=0; i<table->size; i++)
        table->items[i] = NULL;

    return table;
}

void free_item(Ht_item* item) {
    // Frees an item
    free(item->key);
    free(item->value);
    free(item);
}

void free_table(HashTable* table) {
    // Frees the table
    for (int i=0; i<table->size; i++) {
        Ht_item* item = table->items[i];
        if (item != NULL)
            free_item(item);
    }

    free(table->items);
    free(table);
}

void ht_insert(HashTable* table, char* key, char* value) {
    // Create the item
    Ht_item* item = create_item(key, hashString(value, "sha1"));

    // Compute the index
    unsigned long index = hash_function(key);

    Ht_item* current_item = table->items[index];

    if (current_item == NULL) {
        // Key does not exist.
        if (table->count == table->size) {
            // Hash Table Full
            printf("Insert Error: Hash Table is full\n");
            // Remove the create item
            free_item(item);
            return;
        }

        // Insert directly
        table->items[index] = item;
        table->count++;
    } else {
        // Scenario 1: We only need to update value
        if (strcmp(current_item->key, key) == 0) {
            strcpy(table->items[index]->value,
                   hashString(value, "sha1"));
            return;
        // Scenario 2: Collision
        } else {
            // We will handle case this a bit later
            // handle_collision(table, index, item);
            return;
        }
    }
}

char* ht_search(HashTable* table, char* key) {
    // Searches the key in the hashtable
    // and returns NULL if it doesn't exist
    int index = hash_function(key);
    Ht_item* item = table->items[index];

    // Ensure that we move to a non NULL item
    if (item != NULL) {
        if (strcmp(item->key, key) == 0)
            return item->value;
    }
    return NULL;
}

void print_search(HashTable* table, char* key) {
    char* val;
    if ((val = ht_search(table, key)) == NULL) {
        printf("Key:%s does not exist\n", key);
        return;
    }
    else {
        printf("Key: %s, Value: %s\n", key, val);
    }
}

void print_table(HashTable* table) {
    printf("\nHash Table\n-------------------\n");
    for (int i=0; i<table->size; i++) {
        if (table->items[i]) {
            printf("Index: %d, Key: %s, Value: %s\n",
                   i, table->items[i]->key, table->items[i]->value);
        }
    }
    printf("-------------------\n\n");
}
