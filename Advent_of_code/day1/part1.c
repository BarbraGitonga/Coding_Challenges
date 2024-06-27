#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int findelement(char c){
    char nums[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for (int i=0; i<10; i++){
        if (c == nums[i]){
            return c - '0';
        }
    }
    return -1;
}

int tens_first(char* lines){
    int len = strlen(lines);
    int first = 0;
    for(int i = 0; i<len; i++){
        char a = lines[i];
        if(findelement(a) != -1){
            first = findelement(a);
            break;
        }
    }
    return first;
}

int last_ones(char* lines){
    int len = strlen(lines);
    int last;
    for(int i = 0; i<len; i++){
        char a = lines[i];
        if(findelement(a) != -1){
            last = findelement(a);
        }
    }
    return last;
}

int search(const char *filepath){
    FILE* file = fopen(filepath, "r");
    char lines[100];
    char count = 0;
    int sum = 0;
    int fsum, lsum;
    if (file == NULL){
        printf("file is NULL \n");
    }

    while (fgets(lines, sizeof(lines), file)){
        fsum += tens_first(lines);
        lsum += last_ones(lines);
    }
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