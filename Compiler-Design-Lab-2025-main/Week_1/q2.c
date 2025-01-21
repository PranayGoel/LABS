// To reverse the file contents and store in another file. Also display the size of file using file handling function.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr1, *fptr2;
    char sourceFilename[100], destFilename[100];
    long fileSize;
    char c;

    printf("Enter the filename to open for reading: \n");
    scanf("%s", sourceFilename);
    fptr1 = fopen(sourceFilename, "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s for reading\n", sourceFilename);
        exit(1);
    }

    printf("Enter the filename to open for writing: \n");
    scanf("%s", destFilename);
    fptr2 = fopen(destFilename, "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s for writing\n", destFilename);
        fclose(fptr1);
        exit(1);
    }

    fseek(fptr1, 0, SEEK_END);
    fileSize = ftell(fptr1);

    while (fileSize > 0)
    {
        fseek(fptr1, --fileSize, SEEK_SET);
        c = fgetc(fptr1);
        fputc(c, fptr2);
    }

    printf("\nContents of the file have been reversed and copied to %s\n", destFilename);
    fclose(fptr1);
    fclose(fptr2);
}