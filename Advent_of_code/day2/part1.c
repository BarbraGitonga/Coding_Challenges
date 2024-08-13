#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool game_match(char *line) {
    int max_red = 12, max_green = 13, max_blue = 14;
    char *game_start = strchr(line, ':') + 1;  // Start after the colon
    char *token, *subtoken;
    char *saveptr1, *saveptr2;

    // Tokenize the sets
    for (token = strtok_r(game_start, ";", &saveptr1); 
         token != NULL; 
         token = strtok_r(NULL, ";", &saveptr1)) {

        // Tokenize each color in the set
        for (subtoken = strtok_r(token, ",", &saveptr2); 
             subtoken != NULL; 
             subtoken = strtok_r(NULL, ",", &saveptr2)) {

            int count;
            char color[10];
            sscanf(subtoken, "%d %s", &count, color);

            if (strcmp(color, "red") == 0 && count > max_red) return false;
            if (strcmp(color, "green") == 0 && count > max_green) return false;
            if (strcmp(color, "blue") == 0 && count > max_blue) return false;
        }
    }
    return true;
}
int total_games(const char *filepath){
    FILE *file = fopen(filepath, "r");
    char line[256];
    int total = 0;
    int games_id = 1;

    if (file == NULL){
        printf("File not found");
    }

    while (fgets(line, sizeof(line), file)){
        if (game_match(line) == true){
            total+=games_id;
        }
        games_id++;
    }

    fclose(file);
    return total;
}

int main(void){
    const char *filepath = "Game.txt";

    int match = total_games(filepath);
    printf("Total games: %d", match);
    return 0;
}