class Solution {
    func dfs(_ candidates: [Int], _ startPos: Int, _ target: Int, _ cur: inout [Int], _ ans: inout [[Int]]) {
        if target == 0 { 
            ans.append(cur)
            return
        }
        var i = startPos
        while i < candidates.count {
            let val = candidates[i]
            let newValue = target-val
            guard newValue >= 0 else { break }

            cur.append(val)
            dfs(candidates, i+1, newValue, &cur, &ans)
            cur.removeLast()

            while i < candidates.count && candidates[i] == val {
                i += 1
            }
        }
    }
    
    func combinationSum2(_ candidates: [Int], _ target: Int) -> [[Int]] {
        var ans: [[Int]] = []
        var cur: [Int] = []
        
        let candidates = candidates.sorted()
        dfs(candidates, 0, target, &cur, &ans)
        return ans
    }
}