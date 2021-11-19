class Solution {
    func isSubsequence(_ s: String, _ t: String) -> Bool {
        guard t.count >= s.count else { return false }
        
        let s1 = Array(s)
        let s2 = Array(t)
        
        var (i, k) = (0, 0)
        while i < s1.count && k < s2.count {
            if s1[i] == s2[k] { 
                i += 1
            }
            k += 1   
        }
        
        return i == s1.count
    }
}