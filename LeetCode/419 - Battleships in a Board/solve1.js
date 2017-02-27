/**
 * @param {character[][]} board
 * @return {number}
 */

var countBattleships = function(board) {
    var cnt = 0;
    for (var i = 0; i < board.length; ++i) {
        for (var k = 0; k < board[i].length; ++k) {
            if (board[i][k] == 'X') {
                // XXX., X|, X.
                var is_begin = (k === 0) || ((k > 0) && board[i][k-1] === '.');
                var is_another_seg = (i-1 >= 0 && board[i-1][k] === 'X') || (i+1 < board.length && board[i+1][k] === 'X');
                if (is_begin && !is_another_seg) ++cnt;

                is_begin = (i === 0) || ((i > 0) && board[i-1][k] === '.');
                is_long_block = (i+1 < board.length && board[i+1][k] === 'X');
                is_another_seg = (k-1 >= 0 && board[i][k-1] === 'X') || (k+1 < board[i].length && board[i][k+1] === 'X');
                if (is_begin && is_long_block && !is_another_seg) ++cnt;
            }
        }
    }

    return cnt;
};
