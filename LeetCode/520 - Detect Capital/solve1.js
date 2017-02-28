/**
 * @param {string} word
 * @return {boolean}
 */
var detectCapitalUse = function(word) {
    return (word === word.toUpperCase()) || (word === word.toLowerCase())
    || (word[0] === word[0].toUpperCase() && (word.length == 1 || word.slice(1) == word.slice(1).toLowerCase()));
        
};
