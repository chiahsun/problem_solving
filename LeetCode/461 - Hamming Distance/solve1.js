/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function(x, y) {
    var z = x ^ y;
    var cnt = 0;
    while (z) {
        cnt += ((z & 1) > 0 ? 1 : 0);
        z >>= 1;
    }
    return cnt;
};
