#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int findigits(char* window){
    const char *words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char nums[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for (int i=0; i<9; i++){
        const char a = nums[i];

        if(strncmp(window, words[i], strlen(words[i])) == 0){
              return nums[i] -'0';
        }
        else if(window[0] == a){
            return window[0] - '0';
        }
    }
    return -1;
}

char* window(char *lines, char* window_string){
    strncpy(window_string, lines, 4); // Copy the first 5 characters
    window_string[5] = '\0';

    return window_string;
}
int tens_first(char* lines){
    int len = strlen(lines);
    int first = 0;

    for(int i = 0; i<len; i++){
        char wind[4];
        window(lines, wind);
        if(findigits(wind) != -1){
            first = findigits(wind);
            break;
        } 
    }
    return first;
}

int last_ones(char* lines){
    int len = strlen(lines);
    int last = 0;

    for(int i = 0; i<len; i++){
        char wind[4];
        window(lines, wind);
        if (findigits(wind) != -1){
            last = findigits(wind);
        } 
    }
    return last;
}

int search(const char *filepath){
    FILE* file = fopen(filepath, "r");
    char lines[100];
    char count = 0;
    int sum = 0;
    int fsum, lsum = 0;

    if (file == NULL){
        printf("file is NULL \n");
    }

    while (fgets(lines, sizeof(lines), file)){
        fsum += tens_first(lines);
        lsum += last_ones(lines);
    }
    printf("fsum: %d, lsum: %d",fsum, lsum);
    sum = (fsum * 10) + lsum;
    fclose(file);
    return sum;
}

int main(void){
  const char *filepath = "callibaration.txt";

  int total = search(filepath);
  printf("Total = %d", total);
  return 0;
}