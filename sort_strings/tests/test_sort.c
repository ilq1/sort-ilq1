#include "sortings.h"
#include "comparators.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>

// Bubble
void test_bubble_asc() {
    char *data[] = {"cherry", "banana", "apple", "date", "blueberry"};
    const char *expected[] = {"apple", "banana", "blueberry", "cherry", "date"};
    
    sort_bubble(data, (size_t)5, &asc_comparator);
    
    for(int i = 0; i < 5; i++) {
        assert(strcmp(data[i], expected[i]) == 0);
    }
}

void test_bubble_desc() {
    char *data[] = {"cherry", "banana", "apple", "date", "blueberry"};
    const char *expected[] = {"date", "cherry", "blueberry", "banana", "apple"};
    
    sort_bubble(data, 5, &des_comparator);
    
    for(int i = 0; i < 5; i++) {
        assert(strcmp(data[i], expected[i]) == 0);
    }
}

// Insertion
void test_insertion_asc() {
    char *data[] = {"cherry", "banana", "apple", "date", "blueberry"};
    const char *expected[] = {"apple", "banana", "blueberry", "cherry", "date"};
    
    sort_insertion(data, 5, &asc_comparator);
    
    for(int i = 0; i < 5; i++) {
        assert(strcmp(data[i], expected[i]) == 0);
    }
}

void test_insertion_desc() {
    char *data[] = {"cherry", "banana", "apple", "date", "blueberry"};
    const char *expected[] = {"date", "cherry", "blueberry", "banana", "apple"};
    
    sort_insertion(data, 5, &des_comparator);
    
    for(int i = 0; i < 5; i++) {
        assert(strcmp(data[i], expected[i]) == 0);
    }
}

// Merge
void test_merge_asc() {
    char *data[] = {"cherry", "banana", "apple", "date", "blueberry"};
    const char *expected[] = {"apple", "banana", "blueberry", "cherry", "date"};
    
    sort_merge(data, 5, &asc_comparator);
    
    for(int i = 0; i < 5; i++) {
        assert(strcmp(data[i], expected[i]) == 0);
    }
}

void test_merge_desc() {
    char *data[] = {"cherry", "banana", "apple", "date", "blueberry"};
    const char *expected[] = {"date", "cherry", "blueberry", "banana", "apple"};
    
    sort_merge(data, 5, &des_comparator);
    
    for(int i = 0; i < 5; i++) {
        assert(strcmp(data[i], expected[i]) == 0);
    }
}

// Quick
void test_quick_asc() {
    char *data[] = {"orange", "lemon", "lime", "apple", "banana"};
    const char *expected[] = {"apple", "banana", "lemon", "lime", "orange"};
    
    sort_quick(data, 5, &asc_comparator);
    
    for(int i = 0; i < 5; i++) {
        assert(strcmp(data[i], expected[i]) == 0);
    }
}

void test_quick_desc() {
    char *data[] = {"orange", "lemon", "lime", "apple", "banana"};
    const char *expected[] = {"orange", "lime", "lemon", "banana", "apple"};
    
    sort_quick(data, 5, &des_comparator);
    
    for(int i = 0; i < 5; i++) {
        assert(strcmp(data[i], expected[i]) == 0);
    }
}

// Radix
void test_radix_asc() {
    char *data[] = {"orange", "lemon", "lime", "apple", "banana"};
    const char *expected[] = {"apple", "banana", "lemon", "lime", "orange"};
    
    sort_radix(data, 5, &asc_comparator);
    
    for(int i = 0; i < 5; i++) {
        assert(strcmp(data[i], expected[i]) == 0);
    }
}

void test_radix_desc() {
    char *data[] = {"orange", "lemon", "lime", "apple", "banana"};
    const char *expected[] = {"orange", "lime", "lemon", "banana", "apple"};
    
    sort_radix(data, 5, &des_comparator);
    
    for(int i = 0; i < 5; i++) {
        assert(strcmp(data[i], expected[i]) == 0);
    }
}

int main() {
    test_bubble_asc();
    test_bubble_desc();
    test_insertion_asc();
    test_insertion_desc();
    test_merge_asc();
    test_merge_desc();
    test_quick_asc();
    // test_quick_desc();
    test_radix_asc();
    test_radix_desc();
    return 0;
}
