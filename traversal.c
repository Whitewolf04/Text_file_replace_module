#include "traversal.h"

int isDir(const char* fileName){
    char currentPath[FILENAME_MAX];
    getcwd(currentPath, FILENAME_MAX);
    strcat(currentPath, "/");
    strcat(currentPath, fileName);
    struct stat path;
    stat(currentPath, &path);
    return S_ISDIR(path.st_mode);
}


void readDirectory(DIR* directory){
    struct dirent * readDir;

    while((readDir = readdir(directory))){
        printf("\nIterating through file %s\n", readDir->d_name);  // Debug checkpoint
        // Avoid CMakeLists.txt file
        if(strcmp(readDir->d_name, "CMakeLists.txt") == 0){
            printf("This is CMake file!\n"); // Debug checkpoint
            continue;
        }

        // Avoid current folder and upper folder
        if(strcmp(readDir->d_name, ".") == 0 || strcmp(readDir->d_name, "..") == 0){
            printf("This is not a file or folder!\n"); // Debug checkpoint
            continue;
        }   
        
        
        //Check if this is a sub-directory
        if(isDir(readDir->d_name)){
            printf("Sub-directory %s found!\n", readDir->d_name); // Debug checkpoint
            DIR* subDir = opendir(readDir->d_name);

            // Check if directory can be opened
            if(subDir == NULL){
                printf("Couldn't open sub-directory %s\n", readDir->d_name); // Error-printing
                exit(1);
            }

            // Call readDirectory on the sub-directory and then close it
            printf("Opening sub-directory %s\n", readDir->d_name);  // Debug checkpoint
            readDirectory(subDir);

            printf("Closing sub-directory %s\n", readDir->d_name); // Debug checkpoint
            closedir(subDir);
        }

        // Check if file is a text file
        int compare = endsWith(readDir->d_name, ".txt");
        if(compare == 0){
            printf("A text file has been found!\n"); // Debug checkpoint
        } else{
            continue;
        }

        

        // Open the file
        errno = 0;
        FILE *fp = fopen(readDir->d_name, "r");
        printf("File %s has been opened!\n", readDir->d_name); // Debug checkpoint

        if(errno != 0){
            printf("Error when opening file%s\n", readDir->d_name); // Error-printing
            exit(1);
        }

        // Read the file
        char* newFileString = readFile(fp, "dolor");
		printf("\nFinished creating new string for rewrite!\n"); // Debug checkpoint
        fclose(fp);

        // Overwrite old content of the file
        fp = fopen(readDir->d_name, "w");
		rewriteFile(fp, newFileString);

		free(newFileString);
		newFileString = NULL;
        
        // Close file
        fclose(fp);
    }
}
