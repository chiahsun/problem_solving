class Solution {
    func findComplement(_ num: Int) -> Int {
        var mask = -1
        var a = num
        var cnt = 0
        while a > 0 { a >>= 1; mask >>= 1; cnt += 1 }
        for _ in 0..<cnt { mask <<= 1 }
        return ~mask & ~num
    }
}