#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char* readFile(FILE *);
void rewriteFile(FILE *, const char*);
char* replace(char* );
int endsWith(const char*, const char*);
long int sizeOfFile(FILE*);