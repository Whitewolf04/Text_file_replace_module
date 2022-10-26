#include <errno.h>
#include "../text.h"

int main()
{
    // // Open the file
    errno = 0;
    FILE *fp = fopen("./test.txt", "r");
    printf("File has been opened!\n"); // Debug checkpoint

    if (errno != 0)
    {
        printf("Error when opening file\n"); // Error-printing
        exit(1);
    }

    // Read the file
    char *newFileString = readFile(fp, "qui");
    printf("\nFinished creating new string for rewrite!\n"); // Debug checkpoint
    fclose(fp);

    // Overwrite old content of the file
    fp = fopen("./test.txt", "w");
    rewriteFile(fp, newFileString);

    free(newFileString);
    newFileString = NULL;

    // Close file
    fclose(fp);

    // char* test = "Pineapple";
    // test = replace(test, "apple");
    // printf("New string replaced: %s\n", test);

    // char* test2 = (char*) malloc(sizeof(char)*26);
    // strcpy(test2, "hello123hello456helloFinal");
    // test2 = replace(test2, "hello");
    // printf("New string replaced: %s\n", test2);

    // free(test2);
    return 0;
}