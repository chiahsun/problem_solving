class Solution {
    func tribonacci(_ n: Int) -> Int {
        var a = 0
        var b = 0
        var c = 1
        for i in 0..<n {
            (a, b, c) = (a + b + c, a, b)
        }
        return a
    }
}