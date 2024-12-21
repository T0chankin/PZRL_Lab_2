#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "regex.h"

#define MAX_LINE_LENGTH 1024

bool errorChecker(size_t argc,char **argv){
    
}

void replacer(const char *filename, const char *oldText, const char *newText) {
    FILE *file = fopen(filename, "r+");
    char line[MAX_LINE_LENGTH];
    char buffname[] = "temp_file.txt";
    FILE *buff = fopen(buffname, "w");

    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    if (buff == NULL) {
        perror("Error creating buff file");
        fclose(file);
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        char *ptr = strstr(line, oldText);
        if (ptr != NULL) {
            char *restOfLine = ptr + strlen(oldText);
            fprintf(buff, "%.*s%s%s", (int)(ptr - line), line, newText, restOfLine);
        } else {
            fprintf(buff, "%s", line);
        }
    }

    fclose(file);
    fclose(buff);

    if (remove(filename) != 0) {
        perror("Error removing original file");
        return;
    }

    if (rename(buffname, filename) != 0) {
        perror("Error renaming temporary file");
        return;
    }

    printf("Replace completed successfully\n");
}


void operator(size_t argc, char **argv){
    switch (argv[2][1])
    {
    case 'r':
        printf("flag r\n");
        replacer(argv[1],argv[3],argv[4]);
        break;
    case 'd':
        printf("flag d\n");
        replacer(argv[1],argv[3]," ");
        break;
    case 'i':

        switch (argv[3][1])
        {
        case '^':
            printf("flag i ^\n");
            break;
        case '$':
            printf("flag i$\n");
            break;
        }
        break;

    default:
    printf("Error wrong flag\n");
        break;
    }
}