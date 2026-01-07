#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../common.c"

// INSANE solution without regexes or string manip, just math
// see day2 for a more sane solution

#define repeatn(n, dgts) ((n) * (long)pow(10, (dgts)) + (n)) 

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

        /*printf("Min: %ld (%d) Max: %ld (%d)\n", min, min_dgts, max, max_dgts);*/

        /* 1. check first half of left number
           2. if less: add 1, else keep it
           3. check first half of right number
           4. if greater: sub 1, else keep it
           5. keep adding first number until last number */

        // if odd digits
        if (min_dgts % 2 != 0) {
            min_dgts++;
            min = repeatn(pow(10, (int)(min_dgts / 2 - 1)), (int)(min_dgts / 2));
        }

        if (max_dgts % 2 != 0) {
            max_dgts--;
            max = pow(10, max_dgts) - 1;
        }

        printf("%ld %ld\n", min, max);

        long min_fh = min / pow(10, (int)(min_dgts / 2));
        long max_fh = max / pow(10, (int)(max_dgts / 2));

        if (repeatn(min_fh, (int)(min_dgts / 2)) < min) min_fh++;
        if (repeatn(max_fh, (int)(max_dgts / 2)) > max) max_fh--;

        if (min_fh >= pow(10, (int)(min_dgts / 2))) min_dgts += 2;
        if (max_fh < pow(10, (int)((max_dgts - 1) / 2))) max_dgts -= 2;

        int cur_half_dgts = min_dgts / 2 - 1;
        long breakpoint = 0;

        while (min_fh <= max_fh) {
            if (min_fh >= breakpoint) {
                cur_half_dgts++;
                breakpoint = pow(10, cur_half_dgts);
            }

            long val = repeatn(min_fh, cur_half_dgts);
            sum += val;
            min_fh++;

            printf("+%ld\n", val);
        }

        printf("%ld\n", sum);
    }

    free_aoc_input();
    return 0;
}

