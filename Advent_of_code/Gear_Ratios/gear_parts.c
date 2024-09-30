#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int ischaracter(char c){
    if (c != '.' && isdigit(c) != 0){
        return 1; // a symbol
    }
    return 0;
}

int check_left(int row, int col, char **grid){
    int dx[] = {0, -1, 1}; // left, top left, bottom left x co-ordinates
    int dy[] = {-1, -1, -1}; // left, top left, bottom left x co-ordinates

    for(int i = 0; i < 3; i++){
        int x = row + dx[i];
        int y = col + dy[i];
        char z = grid[x][y];

        if(ischaracter(z) == 1){
            return check_right(row, col, grid);
        }
    }
    return 0;
}

int check_top_and_bottom(int row, int col, char **grid){
    /**
     * 
     */
    int dx[] = {-1, 1}; // top, bottom x-co-ordinates
    int dy[] = {0, 0}; //top, bottom y co-ordinates

    for(int i = 0; i < 2; i++){
        int x = row + dx[i];
        int y = col + dy[i];
        char z = grid[x][y];

        if(ischaracter(z) == 1){
            return 1;
        }
    }
    return 0;
}

int check_right_diagonals(int row, int col, char **grid){
    int dx[] = {-1, 1}; // top right, bottom right x coordinate
    int dy[] = {1, 1}; // top right, bottom right y coordinate
    char z = grid[row][col + 1]; // right character

    for(int i = 0; i < 2; i++){ 

        int x = row + dx[i];
        int y = col + dy[i];

        if(ischaracter(z) == 1){
            return 1;
        } 
    }
    return 0;
}

int check_right(int row, int col, char **grid){
    char num[] = grid[row][col];
    char z = grid[row][col + 1]; // right character
    char* z_ptr = &z;
    int dx_right = row;
    int dy_right = col+1;

    if (ischaracter(z) == 1){
        return check_right_for_number(row, col, grid);
    }
    if (isdigit(z) == 1){
        strcat(num, z_ptr);
        int check = check_top_and_bottom(dx_right, dy_right, grid);

        if(check == 1){
            check_right(dx_right, dy_right, grid);
            return num;
        }
        else{
            check_right(dx_right, dy_right, grid);
        }
    }
    else{
        int diags = check_right_diagonals(dx_right, dy_right, grid);
        if (diags == 1){
            return 1;
        }
    }
    return 0;
}
int check_right_for_number(int row, int col, char **grid){
    char* num[3] = grid[row][col];
    
    char z = grid[row][col + 1]; // right character 
    char* z_ptr = &z;
    strcat(num, z_ptr);

    if(isdigit(z) != 0){
        check_right(row, col+1, grid); 
    }

    return num;
}

char** grid_maker(const char *filename){
    FILE *file = fopen(filename, "r");

    if (file == NULL){
        printf("File not found");
    }

    char line[140];
    char grid[140][140];

    while (fgets(line, sizeof line, filename) != NULL){
        for(int i = 0; i < 140; i++){
            for(int j = 0; j < 140; j++){
                for(int k = 0; line[k] != '\0'; k++){
                    grid[i][j] = line[k];
                }
            }
        }
    }
    return grid;
}
int main(void){
    const char* filename = 'text.txt';
    char **grid = grid_maker(filename);
    int ans = 0;
    for(int row = 0; row < 140; row++){
        for(int col = 0; col < 140; col++){
            ans += check_left(row, col, grid);
        }
    }
    printf("ans: %d", ans);
    return 0;
}