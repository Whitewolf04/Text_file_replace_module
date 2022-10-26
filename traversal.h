#pragma once
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#include "text.h"

int isDir(const char*);
void readDirectory(DIR*);