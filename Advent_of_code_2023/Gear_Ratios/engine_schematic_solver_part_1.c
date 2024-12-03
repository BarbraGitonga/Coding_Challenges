#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_ROWS 140
#define MAX_COLS 140

// Function to check if a character is a symbol (non-digit and non-period)
int is_symbol(char ch) {
    return !isdigit(ch) && ch != '.';
}

// Function to check if a position is adjacent to any symbol
int is_adjacent_to_symbol(char schematic[MAX_ROWS][MAX_COLS + 1], int rows, int cols, int i, int j_start, int j_end) {
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) { // checking boundaries are within the grid
            if (di == 0 && dj == 0) continue; // Skip the cell itself
            for (int j = j_start; j <= j_end; j++) { // Check all columns spanned by the number
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                    if (is_symbol(schematic[ni][nj])) {
                        return 1; // Adjacent to a symbol
                    }
                }
            }
        }
    }
    return 0; // Not adjacent to a symbol
}

int main() {
    char schematic[MAX_ROWS][MAX_COLS + 1]; // +1 to account for null terminator
    FILE *file;

    // Open the input file
    file = fopen("Part_numbers.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    // Read the schematic into the 2D array
    for (int i = 0; i < MAX_ROWS; i++) {
        if (!fgets(schematic[i], MAX_COLS + 2, file)) { // +2 to include newline and null terminator
            perror("Error reading file");
            fclose(file);
            return 1;
        }
        // Remove newline character, if present
        char *newline = strchr(schematic[i], '\n');
        if (newline) *newline = '\0';
    }

    fclose(file); // Close the file after reading

    int sum = 0;

    // Traverse the schematic to find part numbers
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (isdigit(schematic[i][j])) { // Start of a number
                int num = 0, j_start = j;

                // Parse the full number
                while (j < MAX_COLS && isdigit(schematic[i][j])) {
                    num = num * 10 + (schematic[i][j] - '0');
                    j++;
                }
                int j_end = j - 1; // End column of the number

                // Check if the number is adjacent to a symbol
                if (is_adjacent_to_symbol(schematic, MAX_ROWS, MAX_COLS, i, j_start, j_end)) {
                    sum += num; // Add to the sum if it's a part number
                }
            }
        }
    }

    printf("The sum of all part numbers is: %d\n", sum);
    return 0;
}
