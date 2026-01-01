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
    const char** items;
    size_t count;
    size_t capacity;
} Lines;

// place file input into array
void file_to_da(const char* path, Lines* xs) {
    FILE* f = fopen(path, "r");
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        buffer[strlen(buffer) - 1] = '\0';
        char* item = malloc(sizeof(buffer));
        strcpy(item, buffer);
        if (xs->count >= xs->capacity) {
            if (xs->capacity == 0) xs->capacity = 4;
            xs->capacity *= 2;
            xs->items = realloc(xs->items, xs->capacity*sizeof(*xs->items));
        }
        xs->items[xs->count++] = item;
    }
    fclose(f);
}

// use macro to get input
#define get_aoc_input(path)\
    Lines input = {0};\
    file_to_da(path, &input);\

#endif
