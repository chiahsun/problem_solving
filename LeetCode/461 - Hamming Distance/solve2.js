/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function(x, y) {
    var z = x ^ y;
    var table = [0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4];
    var cnt = 0;
    while (z > 0) {
        cnt += table[z & 0xf];
        z >>= 4;
    }
    return cnt;
};
