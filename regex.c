#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "regex.h"

#define MAX_LINE_LENGTH 1024

bool errorChecker(size_t argc,char **argv){
    if((argc!=4)||(argc!=5)){
        printf("Error not acceptable arguments");
        return false;
    }
    if(argv[2][0]!='-'){
        printf("Error not flag");
        return false;
    }
    if((argv[2][1]=='i')&&(argv[3][0]!='-')){
        printf("Error not flag");
        return false;
    }
    return true;
}


void replacer(const char *filename, const char *oldText, const char *newText) {
    FILE *file = fopen(filename, "r");
    FILE *tempFile = fopen("temp_file.txt", "w");
    char line[MAX_LINE_LENGTH];
    char *ptr, *start;

    if (file == NULL || tempFile == NULL) {
        perror("Error opening file");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        start = line;
        while ((ptr = strstr(start, oldText)) != NULL) {
            fwrite(start, 1, ptr - start, tempFile);
            fwrite(newText, 1, strlen(newText), tempFile);
            start = ptr + strlen(oldText);
        }
        fwrite(start, 1, strlen(start), tempFile);
    }

    fclose(file);
    fclose(tempFile);

    if (remove(filename) != 0) {
        perror("Error removing original file");
        return;
    }

    if (rename("temp_file.txt", filename) != 0) {
        perror("Error renaming temporary file");
        return;
    }

    printf("Replacement completed successfully\n");
}



void toBegin(const char *filename, const char *word) {
    FILE *file = fopen(filename, "r+");
    char line[MAX_LINE_LENGTH];
    char tempFilename[] = "temp_file.txt";
    FILE *tempFile = fopen(tempFilename, "w");    
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    if (tempFile == NULL) {
        perror("Error creating temporary file");
        fclose(file);
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        fprintf(tempFile, "%s%s\n", word, line);
    }

    fclose(file);
    fclose(tempFile);

    if (remove(filename) != 0) {
        perror("Error removing original file");
        return;
    }

    if (rename(tempFilename, filename) != 0) {
        perror("Error renaming temporary file");
        return;
    }

    printf("word added successfully\n");
}

void toEnd(const char *filename, const char *word) {
    FILE *file = fopen(filename, "r+");
    char line[MAX_LINE_LENGTH];
    char tempFilename[] = "temp_file.txt";
    FILE *tempFile = fopen(tempFilename, "w");

    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    if (tempFile == NULL) {
        perror("Error creating temporary file");
        fclose(file);
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        fprintf(tempFile, "%s%s\n", line, word);
    }

    fclose(file);
    fclose(tempFile);

    if (remove(filename) != 0) {
        perror("Error removing original file");
        return;
    }
    if (rename(tempFilename, filename) != 0) {
        perror("Error renaming temporary file");
        return;
    }

    printf("word added successfully\n");
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
        case 'f':
            
            toBegin(argv[1],argv[4]);
            break;
        case 'b':
            
            toEnd(argv[1],argv[4]);
            break;
        
        default:
            printf("not flag");
            break;
        }
        break;
    default:
        printf("Error wrong flag\n");
        break;
    }
}