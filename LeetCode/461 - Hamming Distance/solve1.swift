class Solution {
    func hammingDistance(_ x: Int, _ y: Int) -> Int {
        var a = x ^ y
        var ans = 0
        while a > 0 {
            ans += 1
            a &= (a-1)
        }
        return ans
    }
}