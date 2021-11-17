class Solution {
    func uniquePathsWithObstacles(_ obstacleGrid: [[Int]]) -> Int {
        var A = Array(repeating: Array(repeating: 1, count: obstacleGrid[0].count), count: obstacleGrid.count)
        
        for i in 0..<obstacleGrid.count {
            for k in 0..<obstacleGrid[0].count {
                if obstacleGrid[i][k] == 1 {
                    A[i][k] = 0
                }
            }
        }
        
        for i in 0..<A.count {
            for k in 0..<A[0].count {
                if (i != 0 || k != 0) && A[i][k] != 0 {
                    A[i][k] = (i-1 >= 0 ? A[i-1][k] : 0) + (k-1 >= 0 ? A[i][k-1] : 0)                    
                }
            }
        }
        
        return A.last!.last!
    }
}