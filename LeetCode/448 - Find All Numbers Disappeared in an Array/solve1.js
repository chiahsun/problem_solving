/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function(nums) {
    nums.sort(function(a, b) { return a - b; })

    var ans = [], prev = 0;
    for (var i = 0; i < nums.length; ++i) {
        var cur = nums[i];
        if (cur > prev) {
          ++prev;
          while (prev < cur) {
            ans.push(prev);
            ++prev;
          }
        }
    }
    ++prev;
    while (prev < nums.length+1) {
        ans.push(prev);
        ++prev;
    }

    return ans;
};
