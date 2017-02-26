/**
 * @param {number} num
 * @return {number}
 */
var findComplement = function(num) {
    if (num === 0) return 0;
    
    if ((num & (0x1 << 30)) > 0) return (~num) & 0x7fffffff;
    
    var cnt = 31;
    for (var mask = 0x1<<31; ; mask >>>=1, cnt -= 1) {
        if ((mask & num) > 0) 
            break;
    }
    
    return (0x1 << (cnt+1)) - num - 1;
};
