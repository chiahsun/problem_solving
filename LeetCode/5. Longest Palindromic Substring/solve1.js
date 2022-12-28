/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    let longest = '';
    for (let i = 0; i < s.length; i++) {
        let d = Math.floor(longest.length / 2);
        // console.log('Cur pos: ', i, ' char: ', s[i]);
        
        // Check even part
        let plow = i - d, phigh = i + d + 1;
        if (plow >= 0 && phigh < s.length) {
          let ok = true;
          while (plow < phigh) {
            if (s[plow] !== s[phigh]) { ok = false; break; }
            plow++;
            phigh--;
          }
          if (ok) {
            plow = i - d, phigh = i + d + 1;
            // console.log('low ', plow, ' ', s[plow], 'high ', phigh, s[phigh]);
            while (plow-1 >= 0 && phigh+1 < s.length && s[plow-1] === s[phigh+1]) {
              plow--;
              phigh++;
              // console.log('low ', plow, ' ', s[plow], 'high ', phigh, s[phigh]);
            }
            longest = s.substring(plow, phigh+1);
            // console.log('even: ', longest);
          }
        }
       
        d = Math.floor(longest.length / 2);
        // Check odd part
        if (longest.length % 2 != 0) { d++; }
        plow = i - d, phigh = i + d;
        if (plow >= 0 && phigh < s.length) {
          let ok = true;
          while (plow < phigh) {
            if (s[plow] !== s[phigh]) { ok = false; break; }
            plow++;
            phigh--;
          }
          // console.log('plow: ', plow, 'phigh: ', phigh);
          if (ok) {
            plow = i - d, phigh = i + d;
            while (plow-1 >= 0 && phigh+1 < s.length && s[plow-1] === s[phigh+1]) {
              plow--;
              phigh++;
            }
            longest = s.substring(plow, phigh+1);
            // console.log('odd: ', longest);
          }
        }
    }
    return longest;
};