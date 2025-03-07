#include <stddef.h>
void merge(char* arr[], int l, int m, int r, int (*comparator)(const char*, const char*))
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    char* L[n1];
    char* R[n2];    
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (comparator(L[i], R[j])<0) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort(char* arr[], int l, int r,int (*comparator)(const char*, const char*))
{
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m,comparator);
        merge_sort(arr, m + 1, r,comparator);
        merge(arr, l, m, r,comparator);
    }
}
void sort_merge(char** arr, size_t size, int (*comparator)(const char*, const char*)){
    merge_sort(arr,0,size-1,comparator);

}