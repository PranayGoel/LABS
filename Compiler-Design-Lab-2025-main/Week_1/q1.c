// To count the number of lines and characters in a file.

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[100];
    char c;
    int charCount = 0, lineCount = 0;

    printf("Enter the filename to open: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open file %s for reading\n", filename);
        exit(1);
    }

    while ((c = fgetc(file)) != EOF) {
        charCount++;
        if (c == '\n') {
            lineCount++;
        }
    }

    // For when the file doesn't end with a newline
    if (charCount > 0 && c != '\n') {
        lineCount++;
    }
    
    printf("Number of characters: %d\n", charCount);
    printf("Number of lines: %d\n", lineCount);

    fclose(file);

    return 0;
}
