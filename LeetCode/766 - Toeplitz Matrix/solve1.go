func Min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func isToeplitzMatrix(matrix [][]int) bool {
    for i := 0; i < len(matrix[0]); i++ {
        for k, last := 0, 0; k < len(matrix) && i+k < len(matrix[0]); k++ {
            cur := matrix[k][i+k]
            if k == 0 {
                last = cur
            } else {
                if cur != last {
                    return false
                }
            }
        }
    }
    
    for i := 1; i < len(matrix); i++ {
        for k, last := 0, 0; k < len(matrix[0]) && i+k < len(matrix); k++ {
            cur := matrix[i+k][k]
            if k == 0 {
                last = cur
            } else {
                if cur != last {
                    return false
                }
            }
        }
    }
        
    return true
}
