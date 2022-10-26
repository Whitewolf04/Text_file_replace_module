#include "../traversal.h"

int main(){
    DIR* testDir = opendir(".");

    // Error-checking for directory opening
    if(testDir == NULL){
        printf("Couldn't open directory\n");
        exit(1);
    }

    readDirectory(testDir);

    closedir(testDir);

    return 0;
}