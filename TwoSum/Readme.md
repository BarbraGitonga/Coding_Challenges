# TwoSum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Link to challenge: [TwoSum](https://leetcode.com/problems/two-sum/description/)

## Pseodocode
```
1. FOR i in the range of 1-length of array:
2.  FOR j in range of i+1 to length of array: (this is so that we do not start from start for each value of i)
3.      SUM of array[i] and array[j]
4.      IF sum is equal to target:
5.          append value of i and j in an array ans
6.          RETURN ans

```
