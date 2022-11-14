class Solution {
    func longestPalindrome(_ s: String) -> Int {
        var s = Array(s)
        var A = Array(repeating: 0, count: 52)
        let aValue = Int(Character("a").asciiValue!)
        let AValue = Int(Character("A").asciiValue!)
        for c in s {
            if c >= "a" && c <= "z" {
                A[Int(c.asciiValue!) - aValue] += 1
            } else {
                A[Int(c.asciiValue!) - AValue + 26] += 1
            }
        }
        var single = false
        var ans = 0
        A.forEach { value in
            let cur = value % 2
            ans += (value - cur)
            single = single || (cur > 0)
        }
        return ans + (single ? 1 : 0)
    }
}