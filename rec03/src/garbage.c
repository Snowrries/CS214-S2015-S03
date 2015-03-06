#include <string.h>
void garbage(char *dest) {
    char *string = "garbagedatagarbagedatagarbagedata";
    memcpy(dest, string, strlen(string) + 1);
}
