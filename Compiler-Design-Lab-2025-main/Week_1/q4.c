// That accepts an input statement, identifies the verbs present in them and performs the following functions
// a. INSERT: Used to insert a verb into the hash table.
// Syntax: insert (char *str)
// b. SEARCH: Used to search for a key(verb) in the hash table. This function is called by INSERT function. If the symbol table already contains an 
// entry for the verb to be inserted, then it returns the hash value of the respective verb. If a verb is not found, the function returns -1.
// Syntax: int search (key)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 8
#define MAX_VERB_LENGTH 20

// Verb structure for hash table
typedef struct {
    char verb[MAX_VERB_LENGTH];
    int count;
} VerbEntry;

// Global hash table and verb array
VerbEntry verbTable[TABLE_SIZE];
char* commonVerbs[] = {"is", "are", "was", "were", "have", "has", "do", "does"};

// Initialize hash table
void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        strcpy(verbTable[i].verb, "");
        verbTable[i].count = 0;
    }
}

// Hash function - simple modulo
int hashFunction(char* verb) {
    int total = 0;
    for (int i = 0; verb[i] != '\0'; i++) {
        total += verb[i];
    }
    return total % TABLE_SIZE;
}

// Search function
int search(char* verb) {
    int index = hashFunction(verb);
    
    // Linear probing
    for (int i = 0; i < TABLE_SIZE; i++) {
        int current = (index + i) % TABLE_SIZE;
        
        if (strcmp(verbTable[current].verb, verb) == 0) {
            return current;  // Verb found
        }
        
        if (strcmp(verbTable[current].verb, "") == 0) {
            return -1;  // Empty slot, verb not found
        }
    }
    
    return -1;
}

// Insert function
void insert(char* verb) {
    // Check if verb already exists
    int existingIndex = search(verb);
    if (existingIndex != -1) {
        verbTable[existingIndex].count++;
        return;
    }
    
    // Find insertion point
    int index = hashFunction(verb);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int current = (index + i) % TABLE_SIZE;
        
        if (strcmp(verbTable[current].verb, "") == 0) {
            strcpy(verbTable[current].verb, verb);
            verbTable[current].count = 1;
            return;
        }
    }
}

// Read file and process verbs
void processFile(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Cannot open file\n");
        return;
    }
    
    char currentWord[MAX_VERB_LENGTH] = {0};
    int wordIndex = 0;
    int ch;
    
    while ((ch = getc(file)) != EOF) {
        // Check if character is alphabetic
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            currentWord[wordIndex++] = ch;
        } else {
            // End of word
            if (wordIndex > 0) {
                currentWord[wordIndex] = '\0';
                
                // Check if current word is a common verb
                for (int i = 0; i < 8; i++) {
                    if (strcmp(currentWord, commonVerbs[i]) == 0) {
                        insert(currentWord);
                        break;
                    }
                }
                
                // Reset word
                wordIndex = 0;
                memset(currentWord, 0, sizeof(currentWord));
            }
        }
    }
    
    fclose(file);
}

// Print hash table
void printHashTable() {
    printf("Verb Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (strcmp(verbTable[i].verb, "") != 0) {
            printf("%s: %d occurrences\n", verbTable[i].verb, verbTable[i].count);
        }
    }
}

int main() {
    initHashTable();
    processFile("test4");  // Replace with your input file
    printHashTable();
    
    return 0;
}
