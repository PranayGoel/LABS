#include <stdio.h>
#include <stdlib.h> // For exit()

int main()
{
    FILE *fptr1, *fptr2;
    char sourceFilename[100], destFilename[100];
    char c;

    // Get the source filename
    printf("Enter the filename to open for reading: \n");
    scanf("%s", sourceFilename);

    // Open source file for reading
    fptr1 = fopen(sourceFilename, "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s for reading\n", sourceFilename);
        exit(1);
    }

    // Get the destination filename
    printf("Enter the filename to open for writing: \n");
    scanf("%s", destFilename);

    // Open destination file for writing
    fptr2 = fopen(destFilename, "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s for writing\n", destFilename);
        fclose(fptr1); // Don't forget to close the source file
        exit(1);
    }

    // Read and copy contents from source to destination
    c = fgetc(fptr1);
    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }

    printf("\nContents copied to %s\n", destFilename);

    // Close both files
    fclose(fptr1);
    fclose(fptr2);

    return 0;
}