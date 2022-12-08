/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {    
    let maxLen = 0;
    
    let m = new Map();
    for (let i = 0; i < s.length; i++) {
        const cur = s[i];
        if (m.has(cur)) {
            const lastStart = m.get(cur);
            for (const key of m.keys()) {
                if (m.get(key) <= lastStart) {
                    m.delete(key);
                } else {
                    m.set(key,  m.get(key) - lastStart - 1);
                }
            }
            m.set(cur, m.size);
        } else {
            m.set(cur, m.size);
            maxLen = Math.max(maxLen, m.size);
        }
    }
    return maxLen;
};