#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_bytes(char *s)
{
    printf("[");
    for (unsigned int i = 0; i < strlen(s); i++) {
        printf("%02x%s", s[i], i < strlen(s) - 1 ? "][" : "");
    }
    printf("]\n");
}

int main(int argc, char **argv)
{
    for (int i = 0; i < argc; i++) {
        puts("####################################");
        printf("arg:    %4i\nlength: %4li bytes\n", i, strlen(argv[i]));
        print_bytes(argv[i]);
        puts(argv[i]); 
    }
    puts("####################################");
}
