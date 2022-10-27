#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


char* readFile(FILE *, const char*, int*);
void rewriteFile(FILE *, const char*);
int endsWith(const char*, const char*);
long int sizeOfFile(FILE*);
char* replace(char*, const char*);