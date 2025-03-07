#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma once
void sort_bubble(char** arr, size_t size, int (*comparator)(const char*, const char*));
void sort_insertion(char** arr, size_t size, int (*comparator)(const char*, const char*));
void sort_merge(char** arr, size_t size, int (*comparator)(const char*, const char*));
void sort_quick(char** arr, size_t size, int (*comparator)(const char*, const char*));
void sort_radix(char** arr, size_t size, int (*comparator)(const char*, const char*));
