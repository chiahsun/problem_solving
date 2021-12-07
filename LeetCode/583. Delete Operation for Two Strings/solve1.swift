class Solution {
    func minDistance(_ word1: String, _ word2: String) -> Int {
        var word1 = Array(word1)
        var word2 = Array(word2)
        var dp = Array(repeating: Array(repeating: 0, count: word2.count), count: word1.count)
        for i in 0..<word1.count {
            for k in 0..<word2.count {
                dp[i][k] = max(
                    i > 0 ? dp[i-1][k] : 0,
                    k > 0 ? dp[i][k-1] : 0,
                    ((word1[i] == word2[k]) ? 1 : 0) + (i > 0 && k > 0 ? dp[i-1][k-1] : 0)
                )
            }
        }
        return word1.count+word2.count - 2*dp.last!.last!
    }
}