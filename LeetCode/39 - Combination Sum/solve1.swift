class Solution {
    func dfs(_ dp: inout [[Int]], _ cur: inout [Int], _ leftVal: Int, _ ans: inout [[Int]]) {
        let A = dp[leftVal]
        for a in A {
            let c = leftVal - a
            guard cur.isEmpty || c <= cur.last! else { continue }
            cur.append(c)
            if a == 0 { ans.append(cur) }
            else      { 
                dfs(&dp, &cur, a, &ans) 
            }
            cur.removeLast()
        }
    }
    
    func combinationSum(_ candidates: [Int], _ target: Int) -> [[Int]] {
        var dp = Array(repeating: [Int](), count: target+1)
        dp[0] = [0]
        
        var candidates = candidates.sorted()
        for c in candidates {
            for i in 1...target {
                if i - c >= 0 && dp[i-c].count > 0 {
                    dp[i].append(i - c)
                }
            }
        }
        
        var ans: [[Int]] = []
        var cur: [Int] = []
        dfs(&dp, &cur, target, &ans)
        
        return ans
    }
}