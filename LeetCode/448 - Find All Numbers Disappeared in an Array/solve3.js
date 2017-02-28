/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function(nums) {
    for (var i = 0; i < nums.length; ++i) {
        var cur = Math.abs(nums[i]);
        if (nums[cur-1] > 0) {
            nums[cur-1] = -nums[cur-1];
        }
    }
    var ans = [];
    for (var i = 0; i < nums.length; ++i) {
        if (nums[i] > 0)
            ans.push(i+1);
    }
    return ans;
};
