#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool game_match(char *line){
    char *color[] = {"red", "green", "blue"};
    int len = strlen(line);
    char var[2];
    int num = 0;
    bool red, blue, green = false;

    for (int i=7; i<len;i++){
        if (isdigit(line[i]) != 0){
            strcpy(var, line[i]);
            strcat(var, line[i+1]);
            num = atoi(var);
            i+=2;
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
    if (red == true && blue == true && green == true){
        return true;
    }
    return false;
}

int total_games(const char *filepath){
    FILE *file = fopen(filepath, "r");
    char lines[100];
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