/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    var max = 0;
    var cnt = 0;
    for (var i = 0; i < nums.length; ++i) {
        if (nums[i]) {
            ++cnt;
        } else {
            max = Math.max(max, cnt);
            cnt = 0;
        }
    }
    return Math.max(max, cnt);
};
