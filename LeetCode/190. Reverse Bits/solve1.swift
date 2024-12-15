class Solution {
    func reverseBits(_ n: Int) -> Int {
        var a = n
        var x = 0
        for i in 0..<32 {
            x <<= 1
            x += (a & 1)
            a >>= 1
        }
        return x
    }
}