#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* report;
static char* localCurrentpath;

void writeReport(char*, const int);
void initializeReport();
void setReportTargetString(const char*);
void setReportDirectory(const char*);
void printReport();

