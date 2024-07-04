/**
 * @file twoSum.c
 * @author your name Barbra Gitonga
 * @brief The function is t o return array indices of elements in 
 *        array num that can be summed up to get target>
 * @version 0.1
 * @date 2024-04-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>

/**
 * @brief 
 * 
 * @param nums - an array of numbers 
 * @param numsSize - length of array of numbers
 * @param target - value of expected sum to be matched
 * @param returnSize - length of array to be returned
 * @return int* - returns an array of the combination of words to be returned
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j, sum = 0;
    int *ans = (int*)malloc(2 * sizeof(int));

    for(i; i < numsSize; i++){
        for(j=i+1; j < numsSize; j++){
            sum = nums[i] + nums[j];
            if (sum == target){
                ans[0] = i;
                ans[1] = j;
                *returnSize = 2;
                return ans;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}