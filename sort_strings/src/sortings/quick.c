#include <stddef.h>
#include <stdlib.h>
void swap(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}
int partition(char** arr , size_t low, size_t high,int (*comparator)(const char*, const char*)) {
    char* p = arr[low];
    size_t i = low;
    size_t j = high;
    while (i < j) {
        while (comparator(arr[i],p)<=0 && i <= high - 1) {
            i++;
        }
        while (comparator(arr[j],p)>0 && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}
void quick_sort(char** arr, size_t low, size_t high,int (*comparator)(const char*, const char*)) {
    if (low < high) {
        int pi = partition(arr, low, high,comparator);
        quick_sort(arr, low, pi - 1,comparator);
        quick_sort(arr, pi + 1, high,comparator);
    }
}

void sort_quick(char** arr, size_t size, int (*comparator)(const char*, const char*)) {
   quick_sort(arr, 0, size-1, comparator);
}