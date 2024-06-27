#include <stdio.h>
#include <string.h>

int findigits(char* window){
    const char *words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char nums[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for (int i=0; i<9; i++){
        const char a = nums[i];

        if(window[0] == a || strncmp(window, words[i], strlen(words[i])) == 0){
              return nums[i] -'0';
        }
    }
    return -1;
}

char* window(char *lines, char* window_string){
    strncpy(window_string, lines, 5); // Copy the first 5 characters
    window_string[5] = '\0';

    return window_string;
}

int tens_first(char* lines){
    int len = strlen(lines);
    int first = 0;

    for(int i = 0; i<len; i++){
        char wind[5];
        window(lines, wind);
        if(findigits(wind) != -1){
            first = findigits(wind); //breaks after finding the first digit
            printf("first: %d\n", first);
            break;
        } 
    }
    return first;
}
int last_ones(char* lines){
    int last = 0;
    char wind[5];

    window(lines, wind);
    if (findigits(wind) != -1){
        last = findigits(wind);
        printf("last: %d\n", last);
    }
    return last;
}
int main(void){
    int ans;
    char digit[] = "one2e45eweqwerfive";
    char zero[] = "00000045two";
    char wind[5];
    int len;

    // ans = findigits(zero);
    // printf("%d\n", ans);
    // window(zero, wind);
    // printf("%s\n", wind);
    // ans = last_ones(digit);
    // printf("%d\n", ans);
    len = strlen(digit);
    // printf("%d", len);

    for(int i=0; i<len; i++){
        if(len-6 != 0){
            window(digit+i, wind);
            printf("%s\n", wind);
            ans = findigits(wind);
            printf("%d\n", ans);
        }
    }
}