#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sort_bubble(char** arr, size_t size, int (*comparator)(const char*, const char*)){
    char *tmp;
    for (size_t i = 0; i<size-1; i++){
        for (size_t j = 0; j<size-1-i;j++){
            if (comparator(arr[j], arr[j+1])>0){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }

        }
    }
}

