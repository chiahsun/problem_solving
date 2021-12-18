/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function(nums) {
    nums.sort(function(a, b) { return a - b; })

    var ans = [];
    var i = 1, pos = 0;
    while (i <= nums.length && pos < nums.length) {
      if (i == nums[pos]) { ++i; ++pos; }
      else if (i > nums[pos]) { ++pos; }
      else { ans.push(i);  ++i; }
    }

    while (i <= nums.length)
        ans.push(i++);

    return ans;
};
