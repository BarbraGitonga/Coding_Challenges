#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Function that iterates over the array to find matching characters in the array.
 * 
 * @param c : the character to be searched for.
 * @return char 
 */
char findelement(char c){
    char characters[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for (int i=0; i<10; i++){
        if (c == characters[i]){
            return characters[i];
        }
    }
    return -1;
}

/**
 * @brief this function looks for the first and last digit in a line,
 *        concatenates it and adds all digits to get the total
 * 
 * @param filepath - path to file
 * @return int 
 */

/**
 * @brief carries out summation of elements in ana array
 * 
 * @param array - an array of charactets
 * @return int - total sum elements
 */
int sum(char *array){
    int i;
    int summation = 0;
    int length = sizeof(array);

    for (i=0; i<length; i++){
        summation+=array[i] - '0';
    }
    return summation;
}
int search(const char *filepath){
    FILE *file = fopen(filepath, "r");
    char lines[200];
    char concatenated[100];
    int ans = 0;

    //check if file is valid
    if (file == NULL){
        printf("file is NULL \n");
    }

    //iterate over all lines
    while((fgets(lines, sizeof(lines), file)) != NULL){
        char *arr = (char*)malloc(5); // store an array of concatenated digits
        char number;
        //iterate over all characters in a line
        while (*lines != '\n'){
            for(size_t j = 0; j<=strlen(lines); j++){
                char a = lines[j];
                number = findelement(a);
            }
            int i = 0;
            // find digis withi the line
            if (number != -1){
                arr[i] = number;
            }
            i++;
            int length = sizeof(arr);
            sprintf(concatenated, "%c%c", arr[0], arr[length-1]); // concatenate the two characters
            free(arr);
        }
    }
    ans = sum(concatenated);
    fclose(file);
    return ans;
}

int main(void){
    const char filepath[] = "callibaration.txt";
    int total = search(filepath);
    printf("total = %d", total);
    
    return 0;
}