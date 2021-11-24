class Solution {
    //  2  = 1+1: 1x1(v)
    //  3  = 1+2: 1x2(v)  = 1+1+1: 1x1x1
    //  4  = 2+2: 2x2(v)  = 1+1+2: 1x1x2    1+1+1+1: 1x1x1x1
    //  5  = 2+3: 2x3(v)  = 1+2+2: 1x2x2    1+1+1+2: 1x1x1x2
    //  6  = 3+3: 3x3(v)  = 2+2+2: 2x2x2    1+1+2+2: 1x1x2x2
    //  7  = 3+4: 3x4(v)  = 2+2+3: 2x2x3(v) 1+2+2+2: 1x2x2x2
    //  8  = 4+4: 4x4     = 2+3+3: 2x3x3(v) 2+2+2+2: 2x2x2x2
    //  9  = 4+5: 4x5     = 3+3+3: 3x3x3(v) 2+2+2+3: 2x2x2x3
    // 10  = 5+5: 5x5     = 3+3+4: 3x3x4(v) 2+2+3+3: 2x2x3x3(v)
    func integerBreak(_ n: Int) -> Int {
        if n == 2 || n == 3 { return n-1 }
        var a = n
        var ans = 1
        while a > 4 {
            ans *= 3
            a -= 3
        }
        return ans * a
    }
}