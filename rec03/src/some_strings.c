#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "garbage.h"

char *copyString1(char *source) {
    char *dest = (char *)malloc(sizeof(char) * (strlen(source)));
    garbage(dest);
    return strcpy(dest, source);
}

char *copyString2(char *source) {
    char *dest = malloc(sizeof(char) * (strlen(source)));
    garbage(dest);
    return strncpy(dest, source, strlen(source)); 
}

int main(int argv, char **argc) {
    char string[] = "Systems Programming";
    char *charptr1, *charptr2;

    printf("Original: \"%s\"\n", string);

    charptr1 = copyString1(string);
    printf("cString1: \"%s\"\n", charptr1);
    free(charptr1);

    charptr2 = copyString2(string);
    printf("cString2: \"%s\"\n", charptr2);
    free(charptr2);
}
