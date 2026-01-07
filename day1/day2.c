#include <stdio.h>
#include "../common.c"

int main(int argc, char* argv[]) {
    get_aoc_input("input.txt", '\n');

    int dial = 50;
    size_t zeroes = 0;
    for (size_t i = 0; i < input.count; i++) {
        size_t old_zeroes = zeroes;
        int magnitude = atoi(input.items[i] + 1);
        size_t hundreds = abs(magnitude / 100);
        int tens = magnitude % 100;

        char direction = input.items[i][0];
        if (input.items[i][0] == 'L') tens *= -1;

        printf("%c %d [%d]\n", direction, magnitude, dial);

        if (dial == 0) {
            // if dial is currently zero
            zeroes += hundreds;
            dial = tens < 0 ? 100 + tens : tens;
        } else {
            // if dial is not zero
            zeroes += hundreds;
            dial += tens;

            if (dial >= 100 || dial <= 0) zeroes++;
            dial = dial < 0 ? 100 + dial : dial % 100;
        }

        size_t new_zeroes = zeroes - old_zeroes;
        if (new_zeroes > 0) printf(" +%zu zeroes\n", new_zeroes);
    }

    printf("Answer: %zu\n", zeroes);

    free_aoc_input();
    return 0;
}

