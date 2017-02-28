/**
 * @param {number[][]} people
 * @return {number[][]}
 */
var reconstructQueue = function(people) {
  people.sort(function(a, b) {
    /*
    if (a[0] != b[0])
        return -(a[0] - b[0]);
    if (a[1] != b[1])
        return (a[1] - b[1]);
    return 0;*/
    return (a[0] != b[0]) ? (b[0] - a[0]) : (a[1] - b[1]);
  });

  console.log(people);

  var ans = [];

  for (var i = 0; i < people.length; ++i) {
    var cur = people[i];
    ans.splice(cur[1], 0, cur);
  }

  return ans;
};

console.log(reconstructQueue([[2,4],[3,4],[9,0],[0,6],[7,1],[6,0],[7,3],[2,5],[1,1],[8,0]]));
