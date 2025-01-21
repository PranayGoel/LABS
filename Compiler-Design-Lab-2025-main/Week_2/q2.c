// To discard preprocessor directives from the given input ‘C’ file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int isPreprocessorDirective(const char *line) {
    if (strncmp(line, "#include", 8) == 0 ||
        strncmp(line, "#define", 7) == 0 ||
        strncmp(line, "#ifdef", 6) == 0 ||
        strncmp(line, "#ifndef", 7) == 0 ||
        strncmp(line, "#endif", 6) == 0) {
        return 1;
    }
    return 0;
}


int main(int argc, char *argv[]) {
    FILE *fa, *fb;
    char c;
    char buffer[MAX_BUFFER_SIZE];
    int bufferIndex = 0;

    fa = fopen("q2_in.c", "r");
    if (fa == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    fb = fopen("q2_out.c", "w");
    if (fb == NULL) {
        printf("Error opening output file.\n");
        fclose(fa);
        return 1;
    }

    while ((c = getc(fa)) != EOF) {
        if (c == '#'){
            bufferIndex = 0;
            buffer[bufferIndex++] = c;
            while ((c = getc(fa)) != EOF && c != '\n' && bufferIndex < MAX_BUFFER_SIZE - 1){
                buffer[bufferIndex++] = c;
            }
            buffer[bufferIndex] = '\0';  // Null-terminate the buffer

            if (!isPreprocessorDirective(buffer)){
                // If not a directive write the # followed by the content to the output file
                for (int i = 0; i < bufferIndex; i++) {
                    putc(buffer[i], fb);
                }
            }

            if (c != EOF && c == '\n'){
                putc(c, fb);
            }
        } 
        else{
            putc(c, fb);
        }
    }

    fclose(fa);
    fclose(fb);
    printf("Preprocessor directives removed and output written to q2_out.c\n");
}