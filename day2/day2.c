#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../common.c"

bool is_invalid(long num) {
    char str_num[256];
    char buf[256];
    int dgts, half_dgts;
    snprintf(str_num, sizeof(str_num), "%ld", num);
    strcpy(buf, str_num);
    dgts = strlen(str_num);
    half_dgts = dgts / 2;

    bool hit = false;

    for (size_t buf_idx = half_dgts; buf_idx > 0 && hit == false; buf_idx--) {
        size_t str_idx = 0;

        if (dgts % buf_idx != 0) continue;

        for (str_idx = 0; str_idx < dgts; str_idx++) {
            if (buf[str_idx % buf_idx] != str_num[str_idx]) break;
        }

        if (str_idx == dgts) { 
            hit = true;
            printf("%ld is invalid!\n", num);
        }
    }

    return hit;
}

int main(int argc, char* argv[]) {
    get_aoc_input("input.txt", ',');

    long sum = 0;
    for (size_t i = 0; i < input.count; i++) {
        // put min and max ranges into min and max
        const char* str = input.items[i];
        char min_buf[256], max_buf[256];
        size_t idx = 0;
        while (*str != '-') min_buf[idx++] = *str++; min_buf[idx] ='\0';
        str++; idx = 0;
        while (*str != '\0') max_buf[idx++] = *str++; max_buf[idx] ='\0';

        long min = atol(min_buf);
        long max = atol(max_buf);
        int min_dgts = strlen(min_buf);
        int max_dgts = strlen(max_buf);

        /*printf("Min: %ld Max: %ld\n", min, max);*/

        while (min <= max) {
            // convert current num to string
            bool invalid = is_invalid(min);
            if (invalid) {
                /*printf("+%ld\n", min);*/
                sum += min;
            }
            min++;
        }
    }

    printf("Answer: %ld\n", sum);

    free_aoc_input();
    return 0;
}

