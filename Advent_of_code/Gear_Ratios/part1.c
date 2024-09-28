#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int ischaracter(char c){
    if (c != '.' || isdigit(c) != 0){
        return 1;
    }
    return 0;
}

int is_digit_to_the_right(int row, int col){
    
}
int search_symbols_around_number(int row, int column, int *position, int **grid){
    int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1}; // x coordinates
    int dy[] = {0, 0, -1, 1, -1, 1, -1, 1}; // y coordinates

    for (int dir = 0; dir < 8; dir++){
        int x = row + dx;
        int y = column + dy;
        char c = grid[x][y];

        if (ischaracter(c) != 0){
            return 1;
        }
    }
    return 0;
}



int digit_build(char* a, char* line){
    char b;
    int len = 140;
    for (int i = -1; i<140; i++){
        if (a)
    }
}

int grid_maker(const char* filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL){
        printf("File not found");
    }

    char line[130];
    int sum = 0;
    char **grid_lines;
    int x, y = 0;

    while (fgets(line, sizeof line, filename) != NULL){
       char character = 
    }
    
}

int main(void){
    const char *filename = "Part_numbers.txt";

}