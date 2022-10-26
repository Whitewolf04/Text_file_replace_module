#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "text.h"
#include "traversal.h"

int main(int argc, char* argv[]){
    DIR * testDir = opendir(".");

    // Error-checking for directory opening
    if(testDir == NULL){
        printf("Couldn't open directory\n"); // Error printing
        exit(1);
    }

    // Read the directory
    readDirectory(testDir);

    // Close the directory
    closedir(testDir);
    return 0;
}

