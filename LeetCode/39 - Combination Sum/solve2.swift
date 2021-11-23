class Solution {
    func dfs(_ candidates: [Int], _ leftVal: Int, _ cur: inout [Int], _ ans: inout [[Int]]) {
        if leftVal == 0 { 
            ans.append(cur)
            return
        }

        for c in candidates where (cur.isEmpty || c >= cur.last!) && leftVal - c >= 0 {
            cur.append(c)
            dfs(candidates, leftVal - c, &cur, &ans)    
            cur.removeLast()
        }
    }
    
    func combinationSum(_ candidates: [Int], _ target: Int) -> [[Int]] {
        var ans: [[Int]] = []
        var cur: [Int] = []
        dfs(candidates, target, &cur, &ans)
        return ans
    }
}