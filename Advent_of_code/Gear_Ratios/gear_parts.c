#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_ROWS 140
#define MAX_COLS 140

// Function to check if a character is a symbol (not a digit or period)
bool is_symbol(char c) {
    return !isdigit(c) && c != '.' && c != '\0' && c != '\n';
}

// Function to check if a number at given position is adjacent to a symbol
bool is_adjacent_to_symbol(char grid[MAX_ROWS][MAX_COLS], int row, int col, int rows, int cols, int num_length) {
    // Check all adjacent positions including diagonals
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + num_length; j++) {
            if (i >= 0 && i < rows && j >= 0 && j < cols) {
                if (is_symbol(grid[i][j])) {
                    return true;
                }
            }
        }
    }
    return false;
}

// Function to extract a number starting at given position and return its length
int get_number_and_length(char grid[MAX_ROWS][MAX_COLS], int row, int col, int* number) {
    char num_str[10] = {0};
    int len = 0;
    
    while (isdigit(grid[row][col + len])) {
        num_str[len] = grid[row][col + len];
        len++;
    }
    
    *number = atoi(num_str);
    return len;
}

int solve_engine_schematic(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file\n");
        return -1;
    }

    char grid[MAX_ROWS][MAX_COLS] = {0};
    int rows = 0, cols = 0;
    char line[MAX_COLS];

    // Read the grid
    while (fgets(line, sizeof(line), file) != NULL) {
        int j = 0;
        for (j = 0; line[j] && line[j] != '\n'; j++) {
            grid[rows][j] = line[j];
        }
        cols = j;
        rows++;
    }
    fclose(file);

    int sum = 0;

    // Process the grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isdigit(grid[i][j])) {
                // Found start of a number
                int number;
                int num_length = get_number_and_length(grid, i, j, &number);
                
                // Check if this number is adjacent to any symbol
                if (is_adjacent_to_symbol(grid, i, j, rows, cols, num_length)) {
                    sum += number;
                }
                
                // Skip the rest of this number
                j += num_length - 1;
            }
        }
    }

    return sum;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    int result = solve_engine_schematic(argv[1]);
    if (result >= 0) {
        printf("Sum of part numbers: %d\n", result);
    }

    return 0;
}