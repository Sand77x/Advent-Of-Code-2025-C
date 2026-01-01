#include <stdio.h>
#include "../common.c"

int main(int argc, char* argv[]) {
    get_aoc_input("input.txt");

    int dial = 50;
    size_t zeroes = 0;
    for (size_t i = 0; i < input.count; i++) {
        char direction = input.items[i][0];
        int magnitude = atoi(input.items[i] + 1);

        if (input.items[i][0] == 'L') {
            // if left
            dial -= magnitude;
            if (dial % 100 == 0) dial = 0;
            if (dial < 0) dial = 100 + (dial % 100);
        } else {
            // if right
            dial += magnitude;
            if (dial > 99) dial = dial % 100;
        }

        if (dial == 0) zeroes++;
    }

    printf("Answer: %zu\n", zeroes);
    return 0;
}

