#include "text.h"

char *readFile(FILE *file, const char *input)
{
	// Create a string to store each string read in
	// and create a new file string to store the string that is going to be rewritten to file
	long int fileSize = sizeOfFile(file);
	char *str = (char*) malloc(40);
	char *newFileString = (char*) malloc(fileSize + 1);

	// Clear out the memory in the newly created strings
	memset(str, 0, strlen(str));
	memset(newFileString, 0, strlen(newFileString));
	int stringCounter = -1;

	do
	{
		char c = fgetc(file);
		if (c == EOF)
		{
			break;
		}
		stringCounter++;
		//    printf("%c", c);
		// Concatenate characters to string until find a space
		if (!isspace(c))
		{
			strncat(str, &c, 1);
		}
		else
		{
			strncat(str, "\0", 1);
			printf("%s", str);
			printf(" ");
			if (strstr(str, input) != NULL)
			{
				str = replace(str, input);
			}
			strncat(newFileString, str, strlen(str));
			strncat(newFileString, &c, 1);
			memset(str, 0, strlen(str));
		}
	} while (1);
	strncat(newFileString, "\0", 1);
	printf("\nNew File String:\n%s", newFileString);

	free(str);
	str = NULL;

	return newFileString;
}

void rewriteFile(FILE *file, const char *string)
{
	printf("\nRewriting back to file!\n");
	fputs(string, file);
	fflush(file);
	printf("Successfully rewritten file!");
}

int endsWith(const char *string, const char *suffix)
{
	int suffixLen = strlen(suffix);
	int stringLen = strlen(string);
	if (suffixLen > stringLen)
	{
		return -1;
	}
	for (int i = 0; i < suffixLen; i++)
	{
		if (suffix[suffixLen - i - 1] != string[stringLen - i - 1])
		{
			return -1;
		}
	}
	return 0;
}

long int sizeOfFile(FILE *file)
{
	fseek(file, 0, SEEK_END);
	long int size = ftell(file);
	fseek(file, 0, SEEK_SET);
	return size;
}

char* replace(char* string, const char* input){
	// printf("Setting up variables\n"); // Debug checkpoint
	char * substring = strcasestr(string, input);
	int length = strlen(string) - strlen(substring) + strlen(input);
	int stringCounter = 0;
	int startIndex = strlen(string) - strlen(substring);
	char output[strlen(string)+1];
	memset(output, 0, strlen(output));
	char* remaining = string+length;
	// printf("Remaining string: %s\n", remaining); // Debug checkpoint

	// printf("Checking for substring in the remaining part of the string\n");  // Debug checkpoint
	if(strcasestr(remaining, input) != NULL){
		remaining = replace(remaining, input);
	}

	// printf("Converting substring part to upper\n"); // Debug checkpoint
	char* iterator = string;
	while(*iterator){
		if((stringCounter >= startIndex) && (stringCounter < length)){
			char temp = toupper(*iterator);
			strncat(output, &temp, 1);
		} else if(stringCounter >= length){
			strncat(output, remaining++, 1);
		} else{
			strncat(output, iterator, 1);
		}

		stringCounter++;
		*iterator++;
	}
	strncat(output, "\0", 1);
	// printf("Converted string successfully, inputted string %s and output string %s\n", string, output); // Debug checkpoint

	memcpy(string, output, sizeof(output));

	return string;
}