/**
 * @param {number[]} findNums
 * @param {number[]} nums
 * @return {number[]}
 */
var nextGreaterElement = function(findNums, nums) {
  var decreasing = [];
  var pos = [];
  var nge = new Array(nums.length);

  for (var i = 0; i < nums.length; ++i) {
      var cur = nums[i];

      while (decreasing.length > 0 && cur > decreasing[decreasing.length-1]) {
          decreasing.pop();
          nge[pos.pop()] = cur;
      }
      decreasing.push(cur);
      pos.push(i);
  }

  var m = {};
  for (var i = 0; i < nums.length; ++i) {
      m[nums[i]] = ((nge[i] === undefined) ? -1 : nge[i]);
  }

  return findNums.map(function(x) { return m[x] });
};
