#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../common.c"

#define JOLTAGE_CNT 12

int main(int argc, char* argv[]) {
    get_aoc_input("input.txt", '\n');

    size_t joltage = 0;
    for (size_t i = 0; i < input.count; i++) {
        char* bank = input.items[i];
        char bt[JOLTAGE_CNT + 1] = {0};

        size_t len = strlen(bank);
        size_t len_offset = len - JOLTAGE_CNT + 1;
        for (size_t bank_idx = 0; bank_idx < len_offset; bank_idx++) {
            char ch = bank[bank_idx];

            for (size_t bt_idx = 0; bt_idx < JOLTAGE_CNT; bt_idx++) {
                if (ch > bt[bt_idx]) {
                    bt[bt_idx] = ch;
                    for (size_t other_idx = bt_idx + 1; other_idx < JOLTAGE_CNT; other_idx++) 
                        bt[other_idx] = '0';
                    break;
                } 
            }
        }

        /*for (size_t bt_idx = 0; bt_idx < JOLTAGE_CNT; bt_idx++) {*/
        /*    printf("%c", bt[bt_idx]);*/
        /*}*/
        /*printf("\n");*/

        for (size_t bank_idx = len_offset; bank_idx < len; bank_idx++) {
            char ch = bank[bank_idx];

            for (size_t bt_idx = 0; bt_idx < JOLTAGE_CNT; bt_idx++) {
                if (ch > bt[bt_idx] && bt_idx >= (len - bank_idx) - (JOLTAGE_CNT - bt_idx)) {
                    bt[bt_idx] = ch;
                    for (size_t other_idx = bt_idx + 1; other_idx < JOLTAGE_CNT; other_idx++)
                        bt[other_idx] = '0';
                    break;
                }
            }
        }

        for (size_t bt_idx = 0; bt_idx < JOLTAGE_CNT; bt_idx++) {
            printf("%c", bt[bt_idx]);
        }
        printf("\n");

        bt[JOLTAGE_CNT] = '\0';
        joltage += atol(bt);
    }

    printf("Answer: %zu", joltage);

    free_aoc_input();
    return 0;
}

