#include <stdio.h>
#include <string.h>
#include "../common.c"

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point* items;
    size_t count;
    size_t capacity;
} Points;

int main(int argc, char* argv[]) {
    get_aoc_input("input.txt", '\n');

    int rows = input.count;
    int cols = strlen(input.items[0]);

    int map[rows + 2][cols + 2];
    memset(map, 0, sizeof(map));

    for (int i = 0; i < rows; i++) {
        char* row = input.items[i];
        for (int j = 0; j < cols; j++)
            map[i+1][j+1] = row[j] == '@' ? 1 : 0;
    }

    int total_papers = 0;
    int current_papers = 0;

    Points picked_up = {0};
    while (1) {
        picked_up.count = 0;
        current_papers = 0;
        for (int i = 1; i < rows + 1; i++) {
            for (int j = 1; j < cols + 1; j++) {
                if (map[i][j] && (map[i-1][j-1] + map[i-1][j] 
                    + map[i-1][j+1] + map[i][j-1] + map[i][j+1] 
                    + map[i+1][j-1] + map[i+1][j] + map[i+1][j+1] < 4)) {
                    Point p = { i, j };
                    da_append(picked_up, p);
                    current_papers++;
                }
            }
        }

        for (int i = 0; i < current_papers; i++) 
            map[picked_up.items[i].x][picked_up.items[i].y] = 0;

        printf("Iteration: %d\n", current_papers);
        if (current_papers == 0) break;
        total_papers += current_papers;
    }


    printf("Answer: %d\n", total_papers);

    free_aoc_input();
    return 0;
}

