/**
 * @param {number} n
 * @return {string[]}
 */
var fizzBuzz = function(n) {
    var ans = [];
    for (var i = 1; i <= n; ++i) {
        var cur;
        if (i % 3 === 0) {
            if (i % 5 === 0) cur = "FizzBuzz";
            else            cur = "Fizz";
        } else if (i % 5 === 0) {
            cur = "Buzz";
        } else {
            cur = i.toString();
        }
        ans.push(cur);
    }
    
    return ans;
};
