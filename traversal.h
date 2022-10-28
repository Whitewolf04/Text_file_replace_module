#pragma once
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#include "text.h"
#include "report.h"


int isDir(const char*);
void readDirectory(char*, const char*, int*);