/**
 * @param {number[]} findNums
 * @param {number[]} nums
 * @return {number[]}
 */
var nextGreaterElement = function(findNums, nums) {
  var ans = [];
  var m = {};
  var nge = new Array(nums.length);

  var max = nums[nums.length-1];
  for (var i = nums.length-1; i >= 0; --i) {
    var cur = nums[i];
    if (cur < max) {
      for (var k = i+1; k < nums.length; ++k) {
        var other = nums[k];
        if (other > cur) {
            nge[i] = other;
            break;
        }
      }
    } else {
       max = cur;
    }
    m[cur] = ((nge[i] === undefined) ? -1 : nge[i]);
  }

  return findNums.map(function(x) { return m[x] });
};
