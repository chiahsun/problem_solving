/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    for (var i = 0; i < nums.length; ++i) {
        for (var k = i+1; k < nums.length; ++k) {
            if (nums[i] + nums[k] == target) {
                return [i, k];
            }
        }
    }
    return [];
};
