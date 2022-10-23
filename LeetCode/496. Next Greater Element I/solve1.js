/**
 * @param {number[]} findNums
 * @param {number[]} nums
 * @return {number[]}
 */
var nextGreaterElement = function(findNums, nums) {
  var ans = [];
  var m = {};
  var nge = new Array(nums.length);

  for (var i = nums.length-1; i >= 0; --i) {
    var cur = nums[i];
    for (var k = i+1; k < nums.length; ++k) {
      var other = nums[k];
      if (other > cur) {
          nge[i] = other;
          break;
      }
    }
    m[cur] = ((nge[i] === undefined) ? -1 : nge[i]);
  }

  return findNums.map(function(x) { return m[x] });
};
