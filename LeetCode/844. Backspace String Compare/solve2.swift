class Solution {

    func backspaceCompare(_ s: String, _ t: String) -> Bool {
        var (s1, s2) = (Array(s), Array(t))
        var (i, k) = (s.count-1, s2.count-1)
        var (skip1, skip2) = (0, 0)
        while i >= 0 || k >= 0 {
            if i >= 0 && s1[i] == "#" { 
                skip1 += 1 
                i -= 1
            } else if k >= 0 && s2[k] == "#" { 
                skip2 += 1
                k -= 1
            } else if (skip1 > 0) {
                i -= 1
                skip1 -= 1
            } else if (skip2 > 0) {
                k -= 1
                skip2 -= 1
            } else {
                if i < 0 || k < 0 || s1[i] != s2[k] {
                    return false
                }
                i -= 1
                k -= 1
            }
        }
        return true
    }
}