/**
 * @param {number[][]} people
 * @return {number[][]}
 */
var reconstructQueue = function(people) {
  people.sort(function(a, b) {
    if (a[0] != b[0])
        return -(a[0] - b[0]);
    if (a[1] != b[1])
        return (a[1] - b[1]);
    return 0;
  });

  var ans = [];

  for (var i = 0, k = 0, higher = 0; i < people.length; ++i) {
    var cur = people[i];
    ans.splice(cur[1], 0, cur);
  }

  return ans;
};

console.log(reconstructQueue([]));
console.log(reconstructQueue([[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]));
