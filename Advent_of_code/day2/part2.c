#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int min_multiplied(char* line) {
    char *games_start = strchr(line, ':') + 1;
    char *token, *subtoken;
    int max_red = 0, max_blue = 0, max_green = 0, num = 0;

    printf("Processing line: %s", line);  // Debug print

    for (token = strtok(games_start, ";"); token != NULL; token = strtok(NULL, ";")) {
        for (subtoken = strtok(token, ","); subtoken != NULL; subtoken = strtok(NULL, ",")) {
            char color[6];
            sscanf(subtoken, "%d %s", &num, color);
            
            printf("Found: %d %s\n", num, color);  // Debug print

            if (strcmp(color, "red") == 0 && num > max_red) max_red = num;
            if (strcmp(color, "blue") == 0 && num > max_blue) max_blue = num;
            if (strcmp(color, "green") == 0 && num > max_green) max_green = num;
        }
    }
    
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