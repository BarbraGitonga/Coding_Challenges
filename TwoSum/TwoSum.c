/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>

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