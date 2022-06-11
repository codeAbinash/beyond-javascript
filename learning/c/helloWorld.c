#include "stdio.h"

int main() {
    char* name = "Abinash";
    char* p = name;
    while (*p != '\0') {
        printf("%c", *p);
        p++;
    }
    return 0;
}