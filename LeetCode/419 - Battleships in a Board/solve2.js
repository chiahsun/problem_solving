/**
 * @param {character[][]} board
 * @return {number}
 */

var countBattleships = function(board) {
    var cnt = 0;
    for (var i = 0; i < board.length; ++i) {
        for (var k = 0; k < board[i].length; ++k) {
            if (board[i][k] === 'X') {
                if ((i > 0 && board[i-1][k] === 'X') || (k > 0 && board[i][k-1] === 'X')) {
                } else {
                    ++cnt;
                }
            }
        }
    }

    return cnt;
};
