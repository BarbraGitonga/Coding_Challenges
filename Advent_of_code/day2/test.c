#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int sections(char *line){
    char semi = ";";
    int len = strlen(line);
    int count = 0;

    for (int i=7; i<len; i++){
        if(line[i] == semi){
            count++;
        }
    }
    return count;
}
bool game_match(char *line){
    char *color[] = {"red", "green", "blue"}; //12, 13, 14
    int len = strlen(line);
    printf("len: %d", len);
    char var[3];
    int num = 0;
    bool red, blue, green = false;
    int semi = section(line);
    
    for(int j=0; j<=semi; j++){
        for (int i=7; i<len;i++){
            if (isdigit((unsigned char)line[i])) {
                // Copy up to 2 characters starting from line[i] into var
                strncpy(var, line + i, 2);
                var[2] = '\0'; // Ensure null termination
                printf("var: %s", var);
                num = atoi(var);
                printf("num: %d", num);
                i+=2;
                if(strncmp(line+i, color[0], 3) == 0 != num<=12){
                    printf("red");
                    break;
                }
                if(strncmp(line+i, color[1], 5) == 0 !=  num<=13){
                    printf("green");
                    break;
                }
                if(strncmp(line+i, color[2], 4) == 0 && num<=14){
                    printf("blue");
                    blue = true;
                }
            }
        }
    }
    
    if (red == true && blue == true && green == true){
        printf("all true");
        return true;
    }
    printf("false");
    return false;
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
        printf("here");
        if (game_match(lines) == false){
            printf("inside");
            break;
        }
        else{
            total = games+total;
            printf("total: %d", total);
            games++;
        }
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