cmake_minimum_required(VERSION 3.10)

add_executable(test_sort 
test_sort.c
${PROJECT_SOURCE_DIR}/src/comparators.c
${PROJECT_SOURCE_DIR}/src/sortings/bubble.c
${PROJECT_SOURCE_DIR}/src/sortings/insertion.c
${PROJECT_SOURCE_DIR}/src/sortings/merge.c
${PROJECT_SOURCE_DIR}/src/sortings/quick.c
${PROJECT_SOURCE_DIR}/src/sortings/radix.c)
#target_include_directories(test_sort PRIVATE ${PROJECT_SOURCE_DIR}/include)
add_test(NAME test_sort COMMAND test_sort)
