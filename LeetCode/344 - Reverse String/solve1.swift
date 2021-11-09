class Solution {
    func swap(_ s: inout [Character], _ i: Int, _ k: Int) {
        (s[i], s[k]) = (s[k], s[i])
    }
    func reverseString(_ s: inout [Character]) {
        var (l, r) = (0, s.count-1)
        while l < r {
            swap(&s, l, r)
            l += 1
            r -= 1
        }
    }
}