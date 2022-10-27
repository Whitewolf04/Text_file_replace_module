#include <errno.h>
#include "../report.h"

int main()
{
    // // Open the file
    // errno = 0;
    // FILE *fp = fopen("./test.txt", "r");
    // printf("File has been opened!\n"); // Debug checkpoint

    // int* changeCounter = (int*) malloc(sizeof(int));
    // (*changeCounter) = 0;

    // if (errno != 0)
    // {
    //     printf("Error when opening file\n"); // Error-printing
    //     exit(1);
    // }

    // // Read the file
    // char *newFileString = readFile(fp, "qui", changeCounter);
    // printf("\nFinished creating new string for rewrite!\n"); // Debug checkpoint
    // fclose(fp);

    // // Overwrite old content of the file
    // fp = fopen("./test.txt", "w");
    // rewriteFile(fp, newFileString);

    // free(newFileString);
    // newFileString = NULL;

    // // Close file
    // fclose(fp);
    // free(changeCounter);

    char* targetString = "Something";
    char* currentFolder = "C:/something/something";

    printf("Initializing report\n");
    initializeReport();
    printf("Setting target string\n");
    setReportTargetString(targetString);
    printf("Setting current folder\n");
    setReportDirectory(currentFolder);
    printf("Putting changes and file name\n");
    writeReport("something/something", 5);
    printf("Generating report\n");
    system("clear");
    printf("Here is the report generated:\n%s", report);
    free(report);

    // char* test2 = (char*) malloc(sizeof(char)*26);
    // strcpy(test2, "hello123hello456helloFinal");
    // test2 = replace(test2, "hello");
    // printf("New string replaced: %s\n", test2);

    // free(test2);
    return 0;
}