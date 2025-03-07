#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortings.h"
#include "comparators.h"
#include "split_into_lines.h"
#ifdef USE_MEMORY_MAPPING
#include "mmap_io.h"
#else
#include "file_io.h"
#endif
void free_lines(char** lines,size_t line_count) {
    if (lines == NULL) return;

    for (size_t i = 0; i<line_count; i++) {
        free(lines[i]);
    }
    free(lines);
}
int main(int argc, char* argv[]){

    char** lines = NULL;
    char* buffer = NULL;
    long actual_lines = 0;

    if (argc != 5){
        fprintf(stderr, "%s", "Incorrect arguments ");
        return -1;
    }
    if (argv[0]<= 0){
        fprintf(stderr, "%s", "invalid count str");
        return -1;
    }
    long line_count = strtol(argv[1], NULL, 10);
    actual_lines = line_count;
    if (line_count <= 0) {
        fprintf(stderr, "%s","Invalid line count");
        return -1;
    }
    
    size_t file_size;
    #ifdef USE_MEMORY_MAPPING
    buffer = mmap_io(argv[2], &file_size);
    if (!buffer) {
        fprintf(stderr, "Failed to read file\n");
        return -1;
    }


#else

buffer = file_io(argv[2], &file_size);
if (!buffer) {
    fprintf(stderr, "Failed to read file\n");
    return -1;
}

#endif

lines = split_into_lines(buffer, file_size, &actual_lines);
if (!lines) {
    fprintf(stderr, "Failed to split into lines\n");
    free(buffer);
    return -1;
}
    
    int (*comparator)(const char*, const char*) = NULL;
    if (strcmp(argv[4], "asc") == 0) {
        comparator = &asc_comparator;
    } else if (strcmp(argv[4], "des") == 0) {
        comparator = &des_comparator;
    } else {
        fprintf(stderr, "%s", "Unknown comparator");
        return -1;
    }
    if (strcmp(argv[3], "bubble") == 0) {
        sort_bubble(lines, actual_lines, comparator);
    } else if (strcmp(argv[3], "insertion") == 0) {
        sort_insertion(lines, actual_lines, comparator);
    } else if (strcmp(argv[3], "merge") == 0) {
        sort_merge(lines, actual_lines, comparator);
    } else if (strcmp(argv[3], "quick") == 0) {
        sort_quick(lines, actual_lines, comparator);
    } else if (strcmp(argv[3], "radix") == 0) {
        sort_radix(lines, actual_lines, comparator);
    } else {
        fprintf(stderr, "%s", "Unknown algo");
        return -1;
    }
    for (long i = 0; i < actual_lines; i++) {
        printf("%s\n", lines[i]);
    }
    free(lines);
    return 0;
}