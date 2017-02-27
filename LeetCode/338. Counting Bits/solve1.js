/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function(num) {
    a = [0, 1]
    while (a.length < num+1)   {
      a = a.concat(a.map(function (x) { return x+1; }));
    }
    return a.slice(0, num+1);
};
