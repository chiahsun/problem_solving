// "sea" "eat"
// d("ea") = 1
// d("sa") = 1
// d("se") = 1

// d("ea") = 1
// d("et") = 1
// d("at") = 1

//   s e a
// e 2 1 2
// a 3 2 1
// t 4 3 2

//   l e e t c o d e
// e 2 1 2 3 4 5 6 7
// t 3 2 3 2 3 4 5 6
// c 4 3 4 3 2 3 4 5
// o 5 4 6 4 3 2 3 4
class Solution {
    func minDistance(_ word1: String, _ word2: String) -> Int {
        var word1 = Array(word1)
        var word2 = Array(word2)
        let M = word2.count
        let N = word1.count
        var dp = Array(repeating: Array(repeating: 0, count: N), count: M)
        
        for i in 0..<M {
            for k in 0..<N {
                if word2[i] == word1[k] {
                    if i > 0 && k > 0 { dp[i][k] = dp[i-1][k-1] }
                    else              { dp[i][k] = i + k }
                } else {
                    if i == 0 && k == 0 { dp[0][0] = 2 }
                    else if i == 0 { dp[0][k] = dp[0][k-1]+1 }
                    else if k == 0 { dp[i][0] = dp[i-1][0]+1 }
                    else           { dp[i][k] = min(dp[i-1][k], dp[i][k-1])+1 }
                }
            }
        }
        return dp.last!.last!
    }
}