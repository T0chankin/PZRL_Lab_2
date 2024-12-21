#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "regex.h"
#define MAX_TEXT_LENGTH 128

typedef struct {
    char *flag[MAX_TEXT_LENGTH];
    char *op1[MAX_TEXT_LENGTH];
    char *op2[MAX_TEXT_LENGTH];
} command;

bool errorChecker(size_t argc,char **argv){
    
}


void operator(size_t argc, char **argv){
    command com;

    sscanf(argv[2], "%[^/]/%[^/]/%[^/]", &com.flag, com.op1, com.op2);
    printf("%s\n%s\n%s\n", com.flag, com.op1, com.op2);
}