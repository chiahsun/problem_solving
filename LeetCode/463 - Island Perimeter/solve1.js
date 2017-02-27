/**
 * @param {number[][]} grid
 * @return {number}
 */
var islandPerimeter = function(grid) {
    var lx = grid.length;
    var ly = grid[0].length;
    function getAdjCount(i, k) {
        return (i > 0 && grid[i-1][k]) + (i+1 < lx && grid[i+1][k]) 
        + (k > 0 && grid[i][k-1]) + (k+1 < ly && grid[i][k+1]);
    }
    
    var incr = 0, decr = 0;
    for (var i = 0; i < lx; ++i) {
        for (var k = 0; k < ly; ++k) {
            if (grid[i][k]) {
                incr += 1;
                decr += getAdjCount(i, k);
            }
        }
    }
    
    return 4 * incr - decr;
};