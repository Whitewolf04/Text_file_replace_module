#include "text.h"

void readFile(FILE * file){
    // Start reading the file
    char * str = malloc(500);
	char * wordToFind = "dolor";
    int stringCounter = 0;
    do{
//        printf("Getting the character!\n");
        char c = fgetc(file);
//        printf("Check for EOF\n");
        if(c == EOF){
            break;
        }
//        printf("%c", c);
		// Concatenate characters to string until find a space
		if(!isspace(c)){
			strncat(str, &c, 1);
		} else{
			strncat(str, "\0", 1);
			printf("%s", str);
			printf("\t");
			if(strcmp(str, wordToFind) == 0){
				str = replace(str);
				fseek(file, -strlen(str), SEEK_CUR);
				fputs(str, file);
				puts(str);
			}
			*str = NULL;
		}


    } while(1);

	free(str);
	str = NULL;

//    printf("\n");
}

 char* replace(char* string){
	// Create a return string and clear out any content in it
	char* tempString = malloc(strlen(string) + 1);
	*tempString = NULL;

	// Loop through the passed in string and convert all character to uppercase
    while(*string){
		char temp = toupper(*string);
		strncat(tempString, &temp, 1);

		// Increment the pointer to get to the next character
		*string++;
	}
	// Put end of string character at the end of return string
	strncat(tempString, "\0", 1);
	return tempString;
 }