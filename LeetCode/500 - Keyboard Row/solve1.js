/**
 * @param {string[]} words
 * @return {string[]}
 */
var findWords = function(words) {
    function getRow(ch) { 
        if ("QWERTYUIOPqwertyuiop".indexOf(ch) !== -1) return 1;
        if ("ASDFGHJKLasdfghjkl".indexOf(ch) !== -1) return 2;
        if ("ZXCVBNMzxcvbnm".indexOf(ch) !== -1) return 3;
        return 0;
    }
    
    function isConsistent(str) {
        if (str.length <= 1) return true;
        var now = getRow(str[0]);
        for (var i = 1; i < str.length; ++i) {
            if (getRow(str[i]) != now)
                return false;
        }
        return true;
    }
    
    var res = [];
    for (var i = 0; i < words.length; ++i) {
        if (isConsistent(words[i]))
            res.push(words[i]);
    }
    return res;
};
