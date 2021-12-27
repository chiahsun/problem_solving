/**
 * @param {number} num
 * @return {number}
 */
var findComplement = function(num) {
    var mask = num;
    for (var cur = 0x1 << 31, en = false; cur !== 0; cur >>>=1) {
        en = en || ((num & cur) > 0);
        if (en) mask = mask | cur;
    }
    return (~num) & mask;
};
