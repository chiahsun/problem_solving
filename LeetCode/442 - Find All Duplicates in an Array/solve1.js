/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function(nums) {
    var ans = [];
    for (var i = 0; i < nums.length; ++i) {
        var pos = Math.abs(nums[i]) - 1;
        if (nums[pos] < 0) ans.push(pos+1);
        else nums[pos] = -nums[pos];
    }
    return ans;
};
