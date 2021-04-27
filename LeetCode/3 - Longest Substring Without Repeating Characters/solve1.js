/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    if (s.length == 0) return 0;
    
    let maxLen = 1;
    // https://stackoverflow.com/questions/2274242/how-to-use-a-variable-for-a-key-in-a-javascript-object-literal
    let m = { [s[0]] : 0 };
    for (let i = 1; i < s.length; i++) {
        const cur = s[i];
        // console.log(m);
        if (! (cur in m)) {
            m[cur] = Object.keys(m).length;
            maxLen = Math.max(maxLen, Object.keys(m).length);
        } else {
            const lastStart = m[cur];
            for (const key in m) {
                if (m[key] <= lastStart) {
                    delete m[key];
                } else {
                    m[key] -= (lastStart+1);
                }
            }
            m[cur] = Object.keys(m).length;
        }
    }
    return maxLen;
};