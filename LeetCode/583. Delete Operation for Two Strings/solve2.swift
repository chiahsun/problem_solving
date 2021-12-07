class Solution {
    func minDistance(_ word1: String, _ word2: String) -> Int {
        var word1 = Array(word1)
        var word2 = Array(word2)
        var dp = Array(repeating: 0, count: word2.count)
        for i in 0..<word1.count {
            for k in stride(from: word2.count-1, to: -1, by: -1) {
                if word1[i] == word2[k] {
                    dp[k] = max((k > 0 ? dp[k-1] : 0) + 1, dp[k])
                }
            }
            for k in 1..<word2.count {
                dp[k] = max(dp[k-1], dp[k])
            }
        }
        return word1.count+word2.count - 2*dp.last!
    }
}