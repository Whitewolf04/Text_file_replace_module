#include "report.h"



void writeReport(char* fileName, const int changeCounter){
    char buffer[sizeof(int)];
    sprintf(buffer, "%d", changeCounter);
    strcat(report, buffer);
    strcat(report, "\t\t");

    char* temp = strstr(fileName, localCurrentpath);
    char* remaining = temp+strlen(localCurrentpath)+1;
    strcat(report, remaining);
    strcat(report, "\n");
    printf("Successfully added change counter and file name\n"); // Debug checkpoint

}

void initializeReport(){
    report = (char*) malloc(sizeof(char)*500);
    localCurrentpath = (char*) malloc(FILENAME_MAX);
    memset(report, 0, strlen(report));
    memset(localCurrentpath, 0, strlen(localCurrentpath));
    printf("Successfully initialized report\n"); // Debug checkpoint
}

void setReportTargetString(const char* string){
    strcat(report, "Target string: ");
    strcat(report, string);
    strcat(report, "\n");
    printf("Successfully set target string on report\n"); // Debug checkpoint
}

void setReportDirectory(const char* currentPath){
    localCurrentpath = currentPath;
    strcat(report, "Search begins in current folder: ");
    strcat(report, currentPath);
    strcat(report, "\n\n\n** Search Report **\n\nUpdates\t\tFile Name\n");
    printf("Successfully set report directory\n"); // Debug checkpoint
}

void printReport(){
    system("clear");
    printf("%s", report);
    free(report);
    free(localCurrentpath);
}