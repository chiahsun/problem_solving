func numMagicSquaresInside(grid [][]int) int {
    ans := 0
    for i := 0; i < len(grid)-2; i++ {
        for k := 0; k < len(grid[0])-2; k++ {
            if is_valid(grid, i, k) {
                ans++
            }
        }
    }
    return ans
}

func is_valid(grid [][]int, r, c int) bool {
    used := make([]bool, 10)
    for i := r; i < r+3; i++ {
        for k := c; k < c+3; k++ {
            cur := grid[i][k]
            if cur == 0 || cur > 9 || used[cur] {
                return false
            }
            used[cur] = true
        }
    }
    
    
    base := [][]int {
        {0, 0},{1, 0},{2, 0},
        {0, 0},{0, 1},{0, 2},
        {0, 0},{0, 2},
    }
    d := [][]int {
        {0, 1},{0, 1},{0, 1},
        {1, 0},{1, 0},{1, 0},
        {1, 1},{1, -1},
    }
    
    for i := 0; i < 8; i++ {
        sum := 0
        x, y := base[i][0]+r, base[i][1]+c
        
        sum += grid[x][y]
        for cnt := 0; cnt < 2; cnt++ {
            x += d[i][0]
            y += d[i][1]
            sum += grid[x][y]
        }
        if sum != 15 {
            return false
        }
    }
    return true
}
