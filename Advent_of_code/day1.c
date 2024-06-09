#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char findelement(char c){
    char nums[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for (int i=0; i<10; i++){
        if (c == nums[i]){
            return nums[i];
        }
    }
    return -1;
}
int search(const char *filepath){
    FILE *file = fopen(filepath, 'r');
    char lines[200];
    int count = 0;
    int ans = 0;

    if (file == NULL){
        printf("file is NULL \n");
    }

    while((fgets(lines, sizeof lines, file)) != NULL){
        char *arr;
        arr = (char*)malloc(5);

        while (fgetc(lines) != '\n'){
            char a = fgetc(lines);
            int i = 0;
            char number = findelement(a);
            if (number != -1){
                arr[i] = number;
            }
            i++;
        }
        int length = len(arr);
        ans = atoi(arr[0]) + atoi(arr[length]);
        free(arr);
    }
    return ans;
}

int main(void){
    char *filepath = "callibaration.txt";
    int total = search(filepath);
    printf(total);
    
    return 0;
}