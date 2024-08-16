#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int min_multiplied(char* line) {
    char *games_start = strchr(line, ':') + 1;
    int max_red = 1, max_blue = 1, max_green = 1;

    printf("Processing line: %s", line);  // Debug print

    char *game_copy = strdup(games_start);  // Create a copy of the game string
    char *game_ptr = game_copy;  // Pointer to free later

    char *set = strtok(game_copy, ";");
    while (set != NULL) {
        char *cube = set;
        while (*cube) {
            while (*cube && isspace(*cube)) cube++;  // Skip leading spaces
            if (!*cube) break;

            int num;
            char color[6] = {0};  // Initialize to zero
            if (sscanf(cube, "%d %5[^,;\n]", &num, color) == 2) {
                // Remove trailing comma if present
                char *comma = strchr(color, ',');
                if (comma) *comma = '\0';
                
                printf("Found: %d %s\n", num, color);  // Debug print

                if (strcmp(color, "red") == 0 && num > max_red) max_red = num;
                else if (strcmp(color, "blue") == 0 && num > max_blue) max_blue = num;
                else if (strcmp(color, "green") == 0 && num > max_green) max_green = num;
            }

            // Move to the next cube in this set
            while (*cube && *cube != ',') cube++;
            if (*cube == ',') cube++;
        }
        set = strtok(NULL, ";");
    }
    
    free(game_ptr);  // Free the copied string
    
    printf("Max values: red=%d, green=%d, blue=%d\n", max_red, max_green, max_blue);  // Debug print
    
    return max_blue * max_green * max_red;
}
int summation(const char *filepath) {
    FILE *file = fopen(filepath, "r");
    char line[256];
    int sum = 0;

    if (file == NULL) {
        printf("File not found: %s\n", filepath);
        return 0;
    }

    printf("File opened successfully\n");  // Debug print

    while (fgets(line, sizeof(line), file)) {
        int game_power = min_multiplied(line);
        sum += game_power;
        printf("Game power: %d, Running sum: %d\n", game_power, sum);  // Debug print
    }

    fclose(file);
    return sum;
}

int main(void) {
    const char *filepath = "Game.txt";

    printf("Starting program\n");  // Debug print
    int match = summation(filepath);
    printf("Minimum cubes power: %d\n", match);
    return 0;
}