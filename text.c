#include "text.h"

char* readFile(FILE * file){
    // Create a string to store each string read in
	// and create a new file string to store the string that is going to be rewritten to file
	long int fileSize = sizeOfFile(file);
    char * str = malloc(40);
	char * newFileString = malloc(fileSize+1);

	// Clear out the memory in the newly created strings
	memset(str, 0, strlen(str));
	memset(newFileString, 0, strlen(newFileString));
	char * wordToFind = "dolor";
	int stringCounter = -1;

    do{
        char c = fgetc(file);
        if(c == EOF){
            break;
        }
		stringCounter++;
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
			}
			strncat(newFileString, str, strlen(str));
			strncat(newFileString, &c, 1);
			memset(str, 0, strlen(str));
		}
    } while(1);
	strncat(newFileString, "\0", 1);
	printf("\nNew File String:\n%s", newFileString);

	free(str);
	str = NULL;

	return newFileString;
}

void rewriteFile(FILE* file, const char* string){
	printf("\nRewriting back to file!\n");
	fputs(string, file);
	printf("Successfully rewritten file!");
}

 char* replace(char* string){
	// Create a return string and clear out any content in it
	char* tempString = malloc(strlen(string) + 1);
	memset(tempString, 0, strlen(tempString));

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

 int endsWith(const char* string, const char* suffix){
	int suffixLen = strlen(suffix);
	int stringLen = strlen(string);
	if(suffixLen > stringLen){
		return -1;
	}
	for(int i = 0; i < suffixLen; i++){
		if(suffix[suffixLen - i - 1] != string[stringLen - i - 1]) {
			return -1;
		}
	}
	return 0;
}

long int sizeOfFile(FILE * file){
	fseek(file, 0, SEEK_END);
	long int size = ftell(file);
	fseek(file, 0, SEEK_SET);
	return size;
}