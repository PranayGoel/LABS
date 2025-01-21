// That takes C program as input, recognizes all the keywords and prints them in uppercase.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 100
#define NUM_KEYWORDS 7

void toUpperCase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

int isKeyword(const char* word, char* keywords[], int num_keywords) {
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *fa, *fb;
    char c;
    char buffer[MAX_BUFFER_SIZE];
    int bufferIndex = 0;
    char *keywords[] = {"include", "define", "if", "else", "while", "for", "return"};

    fa = fopen("q3_in.c", "r");
    if (fa == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    
    fb = fopen("q3_out.c", "w");
    if (fb == NULL) {
        printf("Error opening output file.\n");
        fclose(fa);
        return 1;
    }

    while ((c = getc(fa)) != EOF) {
        if (isalpha(c) || c == '_') {
            buffer[bufferIndex++] = c;

            // Make sure the buffer doesn't overflow
            if (bufferIndex >= MAX_BUFFER_SIZE) {
                bufferIndex = MAX_BUFFER_SIZE - 1;
            }
        } 
        else {
            if (bufferIndex > 0) {
                buffer[bufferIndex] = '\0';
                if (isKeyword(buffer, keywords, NUM_KEYWORDS)) {
                    toUpperCase(buffer);
                }
                for (int i = 0; buffer[i] != '\0'; i++) {
                    putc(buffer[i], fb);
                }
                bufferIndex = 0;
            }
            putc(c, fb);
        }
    }

    // If there's any word left in the buffer ie file ends with word
    if (bufferIndex > 0) {
        buffer[bufferIndex] = '\0';
        if (isKeyword(buffer, keywords, NUM_KEYWORDS)) {
            toUpperCase(buffer);
        }
        for (int i = 0; buffer[i] != '\0'; i++) {
            putc(buffer[i], fb);
        }
    }

    fclose(fa);
    fclose(fb);
    printf("Keywords converted to uppercase and written to q3_out.c\n");
}
