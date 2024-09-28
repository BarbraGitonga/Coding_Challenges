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
            return 1;
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
    char* num[3] = grid[row][col];
    int dx_right = row;
    int dy_left = col;
    
    char z = grid[row][col + 1]; // right character 

    if(ischaracter(z) == 1){
        return  1; 
    }

    else if (isdigit(z) != 0){ // is another digit
        strcat(num, z);
        int check = check_top_and_bottom(dx_right, dy_left, grid);
        if(check == 1){
            check_right(dx_right, dy_left, grid);
        }
        else{
            int diags = check_right_diagonals(row, col, grid);
            if (diags == 1){
                return 1;
            }
        }
    }

    else { // not a symbol or a number ().)
        
    }
    return num;
}