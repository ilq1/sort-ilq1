#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int asc_comparator(const char *a, const char *b) {
    return strcmp(a, b);
}

int des_comparator(const char *a, const char *b) {
    return -strcmp(a, b);
}