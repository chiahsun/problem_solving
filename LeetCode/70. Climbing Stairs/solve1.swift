class Solution {
    func climbStairs(_ n: Int) -> Int {
        var a = 1
        var b = 1
        for i in 1..<n {
            (a, b) = (a+b, a)
        }
        return a
    }
}