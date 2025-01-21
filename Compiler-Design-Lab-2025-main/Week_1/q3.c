// That merges lines alternatively from 2 files and stores it in a resultant file.

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f1ptr, *f2ptr, *resultptr;
    char f1[100], f2[100], result[100];
    int c;

    printf("Enter the first file's name: ");
    scanf("%s", f1);
    f1ptr = fopen(f1, "r");
    if (f1ptr == NULL) {
        printf("Cannot open file %s for reading\n", f1);
        exit(1);
    }

    printf("Enter the second file's name: ");
    scanf("%s", f2);
    f2ptr = fopen(f2, "r");
    if (f2ptr == NULL) {
        printf("Cannot open file %s for reading\n", f2);
        exit(1);
    }

    printf("Enter the resultant file's name: ");
    scanf("%s", result);
    resultptr = fopen(result, "a");
    if (resultptr == NULL) {
        printf("Cannot open file %s for writing\n", result);
        exit(1);
    }

    while (1) {
        while ((c = getc(f1ptr)) != EOF) {
            putc(c, resultptr);
            if (c == '\n') break;
        }

        while ((c = getc(f2ptr)) != EOF) {
            putc(c, resultptr);
            if (c == '\n') break;
        }

        if (feof(f1ptr) && feof(f2ptr)) break;
    }

    printf("Files merged alternately into %s\n", result);
    fclose(f1ptr);
    fclose(f2ptr);
    fclose(resultptr);

    return 0;
}
