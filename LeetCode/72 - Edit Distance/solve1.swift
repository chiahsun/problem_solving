struct Pair: Hashable{
    var s1: [Character]
    var s2: [Character]
}


class Solution {
    func search(_ s1: [Character], _ s2: [Character], _ dp: inout [Pair: Int]) -> Int {
        // print("\(word1) \(word2)")
        if s1.count == 0 || s2.count == 0 { 
            return max(s1.count, s2.count) 
        }
        
        let now = Pair(s1: s1, s2: s2)
        
        if let cnt = dp[now] {
            return cnt
        }
        
        // Check prefix
        for i in 0..<min(s1.count, s2.count) {
            if s1[i] != s2[i] {
                if i > 0 {
                    let ans = search(Array(s1[i...]), Array(s2[i...]), &dp)
                    dp[now] = ans
                    return ans
                }
                break
            }
        }
        
        // Check suffix
        var (i, k) = (s1.count-1, s2.count-1)
        while i >= 0 && k >= 0 && s1[i] == s2[k] {
            i -= 1
            k -= 1
        }
        i += 1
        k += 1
        if i < s1.count {
            let ans = search(Array(s1[..<i]), Array(s2[..<k]), &dp)
            dp[now] = ans
            return ans
        }
        
        var ans = max(s1.count, s2.count)
        
        for i in 0..<s1.count {
            for k in 0..<s2.count {
                if s1[i] == s2[k] {
                    var (iend, kend) = (i+1, k+1)
                    while iend < s1.count && kend < s2.count && s1[iend] == s2[kend] {
                        iend += 1
                        kend += 1
                    }
                    
                    var res = search(Array(s1[...i]), Array(s2[...k]), &dp)
                    if res <= ans {
                        ans = min(ans, res + search(Array(s1[(iend)...]), Array(s2[(kend)...]), &dp)) 
                    }
                }
            }
        }
        // print("min(\(word1), \(word2)): \(ans)")
        dp[now] = ans
        return ans
    }
    
    func minDistance(_ word1: String, _ word2: String) -> Int {
        var s1 = Array(word1)
        var s2 = Array(word2)
        var dp: [Pair: Int] = [:]
        return search(s1, s2, &dp)
    }
}