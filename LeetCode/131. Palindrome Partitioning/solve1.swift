// abba
// [a,b,b,a] [a,bb,a] [abba]

// abcba(3)
// [a,b,c,b,a] [a,bcb,a] [abcba]

// abcbaabcba

// [["a","b","c","b","a","a","b","c","b","a"],["a","b","c","b","a","a","bcb","a"],["a","b","c","b","a","abcba"],["a","b","c","b","aa","b","c","b","a"],["a","b","c","b","aa","bcb","a"],["a","b","c","baab","c","b","a"],["a","b","cbaabc","b","a"],["a","bcb","a","a","b","c","b","a"],["a","bcb","a","a","bcb","a"],["a","bcb","a","abcba"],["a","bcb","aa","b","c","b","a"],["a","bcb","aa","bcb","a"],["a","bcbaabcb","a"],["abcba","a","b","c","b","a"],["abcba","a","bcb","a"],["abcba","abcba"],["abcbaabcba"]]

// 0 1 2 3 4 5 6 7 8 9
// a b c b a a b c b a
// 4 3 * - - 9 8 * - -
// 9 8 7 6 5 - - - - -      
class Solution {
    func partition(_ s: String) -> [[String]] {
        var s = Array(s)
        let N = s.count
        var dp: [[Int]] = Array(repeating: [], count: N)
        for i in 0..<N { dp[i].append(i) }
        for i in 0..<N {
            for k in 1..<min(i+1, N-i) {
                if s[i-k] == s[i+k] {
                    dp[i-k].append(i+k)
                } else {
                    break
                }
            }
            for k in 0..<min(i+1, N-i-1) {
                if s[i-k] == s[i+1+k] {
                    dp[i-k].append(i+1+k)
                } else {
                    break
                }
            }
        }
        // print("dp: \(dp)")
        var ans: [[String]] = []
        var st: [String] = []
        func backtracking(_ cur: Int) {
            if cur == N {
                ans.append(st)
                return
            }
            for next in dp[cur] {
                st.append(String(s[cur...next]))
                backtracking(next+1)
                st.removeLast()
            }
        }
        backtracking(0)
        
        return ans
    }
}