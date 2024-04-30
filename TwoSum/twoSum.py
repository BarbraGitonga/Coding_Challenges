"""this gives the sum of two numbers that will equate to target

Returns:
    _type_: integer
"""
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        lens = len(nums)
        for i in range(0,lens):
            for j in range(i+1, lens):
                sum = nums[i] + nums[j]
                if(sum == target):
                    ans = []
                    ans.append(i)
                    ans.append(j)
                    return ans
  