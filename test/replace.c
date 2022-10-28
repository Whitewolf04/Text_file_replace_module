#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "../text.h"
#include "../traversal.h"


int main(int argc, char* argv[]){
    char* input = (char*) malloc(sizeof(char)*(strlen(argv[1])+1));
    memset(input, 0, strlen(input));
    strcpy(input, argv[1]);

    int* changeCounter = (int*) malloc(sizeof(int));
    (*changeCounter) = 0;

    char* currentPath = (char*) malloc(FILENAME_MAX);
    getcwd(currentPath, FILENAME_MAX);

    initializeReport();
    setReportTargetString(input);
    setReportDirectory(currentPath);

    readDirectory(currentPath, input, changeCounter);

    printf("Close directory successfully!\n"); // Debug checkpoint

    printf("Total number of updates: %d\n", *changeCounter);  // Debug checkpoint

    printReport();

    free(input);
    free(changeCounter);
    
    return 0;
}

