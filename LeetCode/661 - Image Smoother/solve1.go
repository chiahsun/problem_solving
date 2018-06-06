func imageSmoother(M [][]int) [][]int {
    nrow, ncol := len(M), len(M[0])
    
    ans := make([][]int, nrow)
    for i := 0; i < nrow; i++ {
        ans[i] = make([]int, ncol)
    }
    
    for i, row := range(ans) {
        for k := 0; k < ncol; k++ {
            sum, count := 0, 0
            for dr := -1; dr <= 1; dr++ {
                for dc := -1; dc <= 1; dc++ {
                    r := i + dr
                    c := k + dc
                   
                    if (r >= 0 && r < nrow && c >= 0 && c < ncol) {
                        sum += M[r][c]
                        count++
                    }
                }
            }
            row[k] = sum / count
        }
    }
    
    return ans
}
