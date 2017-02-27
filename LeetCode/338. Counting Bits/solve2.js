/**
 * @param {number} num
 * @return {number[]}
 */

var countBits = function(num) {
    var a = [0];
    function isPow2(x) {
        return ((x - 1) & x) === 0;
    }
    for (var i = 1, base = 0; i < num+1; ++i) {
        if (isPow2(i)) {
            base = i;
            a.push(1);
        } else {
            a.push(a[i-base]+1);
        }
    }
    return a;
};
