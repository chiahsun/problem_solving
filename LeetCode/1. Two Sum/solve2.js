/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    map = {};
    for (var i = 0; i < nums.length; ++i) {
        var cur = nums[i], other = target-cur;
        if (map[other] !== undefined) {
            return [map[other], i];
        }
        map[cur] = i;
    }
    return [];
};
