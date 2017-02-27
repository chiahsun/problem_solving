/**
 * @param {number} num
 * @return {number[]}
 */

var countBits = function(num) {
    var a = new Array(num+1);
    a[0] = 0;
    for (var i = 1; i < num+1; ++i) {
        a[i] = a[i>>1] + i%2;
    }
    return a;
};
