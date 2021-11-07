/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let m = {};
    for (let i = 0; i < nums.length; i++) {
        const cur = nums[i];
        const other = target - cur;
        if (other in m) {
            return [m[other], i];
        } else {
            m[cur] = i;
        }
    }
    return [];
};
