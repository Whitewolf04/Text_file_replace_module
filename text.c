#include "text.h"

void readFile(FILE * file){
    // Start reading the file
    char* str = "";
    int stringCounter = 0;
    do{
        printf("Getting the character!\n");
        char c = fgetc(file);
        printf("Check for EOF\n");
        if(feof(file)){
            break;
        }
        printf("%c", c);
        char* temp = c;
        str = strcat(str, temp);

    } while(1);
    printf("%s", str);
    printf("\n");
}

// char* replace(char* string){
    
// }