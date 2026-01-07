#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// from tsoding :-)
#define da_append(xs, x)\
    do {\
    if (xs.count >= xs.capacity) {\
        if (xs.capacity == 0) xs.capacity = 4;\
        xs.capacity *= 2;\
        xs.items = realloc(xs.items, xs.capacity*sizeof(*xs.items));\
    }\
    xs.items[xs.count++] = x;\
    } while(0)

// struct for file input
typedef struct {
    char** items;
    size_t count;
    size_t capacity;
} Lines;

// place file input into array
#define get_aoc_input(path, delimeter)\
    Lines input = {0};\
    FILE* f = fopen(path, "r");\
    char buffer[512];\
    int c;\
    int buf_idx = 0;\
    while ((c = fgetc(f)) != EOF) {\
        char ch = (char)c;\
        if (ch != delimeter) {\
            buffer[buf_idx] = ch;\
            buf_idx++;\
        } else {\
            if (buf_idx == 0) continue;\
            buffer[buf_idx] = '\0';\
            char* item = malloc(buf_idx + 1);\
            strcpy(item, buffer);\
            da_append(input, item);\
            buf_idx = 0;\
        }\
    }\
    if (buf_idx > 0) {\
        buffer[buf_idx - 1] = '\0';\
        char* item = malloc(buf_idx + 1);\
        strcpy(item, buffer);\
        da_append(input, item);\
    }\
    fclose(f);\

#define free_aoc_input()\
    for (size_t i = 0; i < input.count; i++) {\
        free(input.items[i]);\
    }\

#endif
