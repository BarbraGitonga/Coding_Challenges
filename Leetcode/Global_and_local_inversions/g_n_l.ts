function isIdealPermutation(nums: number[]): boolean {
    let maxSoFar = -1;

    for (let i = 0; i < nums.length - 2; i++) {
        maxSoFar = Math.max(maxSoFar, nums[i]);
        if (maxSoFar > nums[i + 2]) {
            return false;
        }
    }

    return true;
};

let ans = false;

const nums1 = [1,0,2];
const nums2 = [1,2,0];

ans = isIdealPermutation(nums1);
console.log(ans);

ans  = isIdealPermutation(nums2);
console.log(ans);