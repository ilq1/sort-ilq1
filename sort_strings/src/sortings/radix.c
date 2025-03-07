#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ASCII_SIZE 256
char get_char_at_index(const char* str, int index) {
    if (index >= strlen(str)) {
        return 0;
    }
    return str[index];
}
void counting_sort(char** arr, size_t size, int index, int (*comparator)(const char*, const char*)) {
    int count[ASCII_SIZE] = {0};
    char** output = malloc(size * sizeof(char*));
    for (size_t i = 0; i < size; i++) {
        char ch = get_char_at_index(arr[i], index);
        count[(unsigned char)ch]++;
    }
    for (int i = 1; i < ASCII_SIZE; i++) {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        char ch = get_char_at_index(arr[i], index);
        output[count[(unsigned char)ch] - 1] = arr[i];
        count[(unsigned char)ch]--;
    }
    for (size_t i = 0; i < size; i++) {
        arr[i] = output[i];
    }
    free(output);
}
void sort_radix(char** arr, size_t size, int (*comparator)(const char*, const char*)) {
    if (size == 0) {
        return;
    }
    size_t max_len = 0;
    for (size_t i = 0; i < size; i++) {
        size_t len = strlen(arr[i]);
        if (len > max_len) {
            max_len = len;
        }
    }
    for (int i = max_len - 1; i >= 0; i--) {
        counting_sort(arr, size, i, comparator);
    }
    if (comparator(arr[0], arr[size-1]) > 0) {
        for (size_t i = 0; i < size/2; i++) {
            char* temp = arr[i];
            arr[i] = arr[size - i - 1];
            arr[size-i-1] = temp;
        }
    }
}
