#include "traversal.h"

int isDir(const char* pathName){
    struct stat path;
    stat(pathName, &path);
    return S_ISDIR(path.st_mode);
}


// TO-DO: Full path of text file in subfolder is not passed through recursion
void readDirectory(char* currentPath, const char* input, int* changeCounter){
    struct dirent * readDir;
    DIR* directory = opendir(currentPath);
    char tempPath[FILENAME_MAX];

    // Check if directory can be opened
    if(directory == NULL){
        printf("Couldn't open sub-directory %s\n", readDir->d_name); // Error-printing
        exit(1);
    }

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

        // Get full path of the current file/directory
        // getcwd(currentPath, FILENAME_MAX);
        memcpy(tempPath, currentPath, FILENAME_MAX);
        strcat(tempPath, "/");
        strcat(tempPath, readDir->d_name);
        
        
        //Check if this is a sub-directory
        if(isDir(tempPath)){
            printf("Sub-directory %s found!\n", readDir->d_name); // Debug checkpoint
            // DIR* subDir = opendir(currentPath);

            // Call readDirectory on the sub-directory and then close it
            printf("Opening sub-directory %s\n", readDir->d_name);  // Debug checkpoint
            readDirectory(tempPath, input, changeCounter);

            printf("Closing sub-directory %s\n", readDir->d_name); // Debug checkpoint
        }

        // Check if file is a text file
        int compare = endsWith(readDir->d_name, ".txt");
        if(compare == 0){
            printf("A text file has been found!\n"); // Debug checkpoint
        } else{
            continue;
        }

        

        // Open the file
        printf("Current path: %s\n", currentPath); // Debug checkpoint
        errno = 0;
        FILE *fp = fopen(tempPath, "r");
        printf("File %s has been opened!\n", readDir->d_name); // Debug checkpoint

        if(errno != 0){
            printf("Error when opening file %s\n", readDir->d_name); // Error-printing
            fclose(fp);
            continue;
        }

        // Read the file
        char* newFileString = readFile(fp, input, changeCounter);
		printf("\nFinished creating new string for rewrite!\n"); // Debug checkpoint
        fclose(fp);

        // Overwrite old content of the file
        fp = fopen(tempPath, "w");
		rewriteFile(fp, newFileString);

		free(newFileString);
		newFileString = NULL;

        // writeReport(tempPath, *changeCounter);
        
        // Close file
        fclose(fp);
    }
    
    // printf("Closing current directory\n");  // Debug checkpoint
    closedir(directory);
}
