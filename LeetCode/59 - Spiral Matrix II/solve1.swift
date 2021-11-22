class Solution {
    //  1  2  3 4
    // 12 13 14 5
    // 11 16 15 6
    // 10  9  8 7
    func generateMatrix(_ n: Int) -> [[Int]] {
        var ans = Array(repeating: Array(repeating: 0, count: n), count: n)
        
        var (I, K) = (n, n)
        var (i, k) = (0, -1)
        var (di, dk) = (0, K)
        var dir = 0
        for val in 1...n*n {
            if di != 0 {
                let d = (di > 0) ? 1 : -1
                i += d
                di -= d
            }
            if dk != 0 {
                let d = (dk > 0) ? 1 : -1
                k += d
                dk -= d
            }
            ans[i][k] = val
            if di == 0 && dk == 0 {
                switch dir {
                    case 0: 
                        I -= 1
                        (di, dk) = (I, 0)
                    case 1:
                        K -= 1
                        (di, dk) = (0, -K)
                    case 2:
                        I -= 1
                        (di, dk) = (-I, 0)
                    case 3:
                        K -= 1
                        (di, dk) = (0, K)
                    default:
                        break
                }
                dir = (dir+1)%4
            }
        }
        return ans
    }
}