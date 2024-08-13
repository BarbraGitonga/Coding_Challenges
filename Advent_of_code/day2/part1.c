#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool game_match(char *line){
    const char *color[] = {"red", "green", "blue"};
    int len = strlen(line);
    char var[3];
    int num = 0;
    bool red = false, blue = false, green = false;

    for (int i=7; i<len; i++){
        if (isdigit((unsigned char)line[i])) {
            // Copy up to 2 characters starting from line[i] into var
            strncpy(var, line + i, 2);
            var[2] = '\0'; // Ensure null termination
            num = atoi(var);
            if (i < len-3){
                 i+=2;
            }
            if(strncmp(line+i, color[0], 3) == 0 && 12<=num){
               red = true;
            }
            if(strncmp(line+i, color[1], 5) == 0 && 13<=num){
               green = true;
            }
            if(strncmp(line+i, color[2], 4) == 0 && 14<=num){
               blue = true;
            }
        }
    }
    return (red && blue && green);
}

int total_games(const char *filepath){
    FILE *file = fopen(filepath, "r");
    char lines[1024];
    int total = 0;
    int games = 1;

    if (file == NULL){
        printf("File not found");
    }

    while (fgets(lines, sizeof(lines), file)){
        if (game_match(lines) == true){
            total+=games;
        }
        games++;
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