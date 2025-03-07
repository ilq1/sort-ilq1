#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sort_insertion(char** arr, size_t size, int (*comparator)(const char*, const char*)){
    for (size_t i = 1; i < size; i++) {
        size_t j = i;
        while (j > 0 && comparator(arr[j - 1], arr[j]) > 0) {
            char* temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
}
