#include <stdio.h>
#include <string.h>
//#include "mylib.h"
#ifndef __MYLIB_C
#define gloria poop

void print_string(char *s)
{
    puts(s);
    printf("[");
    for (unsigned int i = 0; i < strlen(s); i++) {
        printf("%02x%s", s[i], i < strlen(s) - 1 ? "][" : "");
    }
    printf("]\n");
}


#endif
