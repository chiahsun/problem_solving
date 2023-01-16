class Solution {
    func longestCommonSubsequence(_ text1: String, _ text2: String) -> Int {
        var s1 = Array(text1)
        var s2 = Array(text2)
        var A = Array(repeating: Array(repeating: 0, count: s2.count), count: s1.count)
        
        for i in 0..<s1.count {
            for k in 0..<s2.count {
                let val = s1[i] == s2[k] ? 1 : 0
                A[i][k] = max(
                    val,
                    (i > 0 && k > 0) ? val + A[i-1][k-1] : 0,
                    i > 0 ? A[i-1][k] : 0,
                    k > 0 ? A[i][k-1] : 0
                )
            }
        }
    
        return A.last!.last!
    }
}