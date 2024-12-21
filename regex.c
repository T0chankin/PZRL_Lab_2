#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "regex.h"
#define MAX_TEXT_LENGTH 128
#define MAX_WORD_LENGTH 128

typedef struct {
    char flag;
    char *op1[MAX_TEXT_LENGTH];
    char *op2[MAX_TEXT_LENGTH];
} command;

bool errorChecker(size_t argc,char **argv){
    
}


void operator(size_t argc, char **argv){
    command com;

    sscanf(argv[2], "%c/%[^/]/%[^/]", &com.flag, com.op1, com.op2);
    printf("%c\n%s\n%s\n", com.flag, com.op1, com.op2);

}