class Solution {
    func fib(_ n: Int) -> Int {
        var a = 0
        var b = 1
        for i in 0..<n {
            let c = a
            a = a + b
            b = c
        }
        return a
    }
}