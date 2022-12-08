/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {    
    let maxLen = 0;
    
    let acc = [];
    for (let i = 0; i < s.length; i++) {
        const cur = s[i];
        if (acc.includes(cur)) {
            const lastStart = acc.indexOf(cur);
            while (true) {
              const removed = acc.shift();
              if (removed == cur) {
                  break;
              }
            }
            acc.push(cur);
        } else {
            acc.push(cur);
            maxLen = Math.max(maxLen, acc.length);
        }
    }
    return maxLen;
};