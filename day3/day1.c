#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../common.c"

int main(int argc, char* argv[]) {
    get_aoc_input("input.txt", '\n');

    size_t joltage = 0;
    for (size_t i = 0; i < input.count; i++) {
        char* bank = input.items[i];
        char bf = '0', bs = '0'; // '0' char in %d

        size_t len = strlen(bank);
        for (size_t bank_idx = 0; bank_idx < len - 1; bank_idx++) {
            char ch = bank[bank_idx];

            if (ch > bf) {
                bf = ch;
                bs = '0';
            } else {
                if (ch > bs) bs = ch;
            }
        }

        // check if last ch is better than bs
        if (bank[len - 1] > bs) bs = bank[len - 1];

        printf("%c %c\n", bf, bs);
        joltage += (bf - 48) * 10 + (bs - 48);
    }

    printf("Answer: %zu", joltage);

    free_aoc_input();
    return 0;
}

