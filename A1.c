#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "text.h"

int isDir(const char* fileName);

int main(int argc, char* argv[]){
    DIR * testDir = opendir("D:\\C_learning\\test");
    struct dirent * readDir;

    // Error-checking for directory opening
    if(testDir == NULL){
        printf("Couldn't open directory\n");
        return 0;
    }

    // Open the directory
    while((readDir = readdir(testDir))){
        // Check if file is a text file
        int compare = endsWith(readDir->d_name, ".txt");
        if(compare == 0){
            printf("A file has been found!\n"); // Debug checkpoint
        } else{
            // If not a text file, continue iterating
            continue;
        }

        // TO-DO: Check if this is a sub-directory
        if(isDir(readDir->d_name) == 0){

        }

        // Open the file
        FILE *fp = fopen(readDir->d_name, "r");
        printf("File has been opened!\n"); // Debug checkpoint

        char* newFileString = readFile(fp);
		printf("\nFinished creating new string for rewrite!\n");

		freopen(readDir->d_name, "w", fp);
		rewriteFile(fp, newFileString);

		free(newFileString);
		newFileString = NULL;
        fclose(fp); // Close file stream
		fflush(fp);
    }
    closedir(testDir);
    return 0;
}



int isDir(const char* fileName){
    struct stat path;
    stat(fileName, &path);
    return S_ISDIR(path.st_mode);
}
