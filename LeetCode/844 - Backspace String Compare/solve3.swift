extension String {
    func decre(_ i: String.Index) -> String.Index {
        if i != startIndex && i != endIndex {
            return index(i, offsetBy: -1)
        }
        return endIndex
    }
}

class Solution {
    func backspaceCompare(_ s: String, _ t: String) -> Bool {
        var (i, k) = (s.index(s.endIndex, offsetBy: -1), t.index(t.endIndex, offsetBy: -1))
        var (skip1, skip2) = (0, 0)
        while i != s.endIndex || k != t.endIndex {
            if i != s.endIndex && s[i] == "#" { 
                skip1 += 1 
                i = s.decre(i)
            } else if k != t.endIndex && t[k] == "#" { 
                skip2 += 1
                k = t.decre(k)
            } else if (skip1 > 0) {
                i = s.decre(i)
                skip1 -= 1
            } else if (skip2 > 0) {
                k = t.decre(k)
                skip2 -= 1
            } else {
                if (i == s.endIndex || k == t.endIndex) || s[i] != t[k] {
                    return false
                }
                i = s.decre(i)
                k = t.decre(k)
            }
        }
        return true
    }
}