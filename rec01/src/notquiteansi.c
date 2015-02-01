#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 
 * If you aren't glad you're not writing ANSI C you will be after this!
 */
typedef struct {
    int size;
    //Flexible array member at the end of a struct
    long long array[];
} sarray;

//Function prototypes
void fill_array(int length, long long *ia);
void print_sarray(sarray *s, long long *ia);

void fill_array(int length, long long *ia) {
    for (int i = 0; i < length; i++) {
        //Implicit promotion
        ia[i] = rand() % 1000;
    }
}

void print_sarray(sarray *s, long long *ia) {
    printf("[ ");
    for (int i = 0; i < s->size; i++) {
        //Readability is a bit suspect here...
        printf("%lld%s", s->array[i], i < s->size - 1 ? ", " : " ");
        ia[i] = s->array[i];
    }
    printf("] size: %d\n", s->size);
}

int main() {
    //Intermixing code and declarations
    for (int i = 0; i < 10; i++) {
        //Variable-length array
        long long ia[i];
        /*
         * Note that I'm allocating enough space to fill the
         * flexible array member with i 
         */
        sarray *s = 0;
        if ((s = malloc(sizeof(sarray) + sizeof(long long) * i))) {
                s->size = i;
                fill_array(i, s->array);
                print_sarray(s, ia);
                free(s);
        }
    }
}

/*
 * There's a bunch of non-ANSI stuff in here.
 * That comment at the top is ANSI C compliant though...
 */
