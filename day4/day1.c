#include <stdio.h>
#include <string.h>
#include "../common.c"

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

    int papers = 0;
    for (int i = 1; i < rows + 1; i++) {
        for (int j = 1; j < cols + 1; j++) {
            if (map[i][j] && map[i-1][j-1] + map[i-1][j] 
                + map[i-1][j+1] + map[i][j-1] + map[i][j+1] 
                + map[i+1][j-1] + map[i+1][j] + map[i+1][j+1] < 4)
                papers++;
        }
    }

    /*for (int i = 0; i < rows + 2; i++) {*/
    /*    char* row = input.items[i];*/
    /*    for (int j = 0; j < cols + 2; j++)*/
    /*        printf("%d", map[i][j]);*/
    /*    printf("\n");*/
    /*}*/

    printf("Answer: %d", papers);

    free_aoc_input();
    return 0;
}

