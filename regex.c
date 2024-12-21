#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "regex.h"

bool errorChecker(size_t argc,char **argv){
    
}
replacer(char **argv){

}

void operator(size_t argc, char **argv){
    switch (argv[2][1])
    {
    case 'r':
        printf("flag r\n");
        break;
    case 'd':
        printf("flag d\n");
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
    printf("ti loh\n");
        break;
    }
}