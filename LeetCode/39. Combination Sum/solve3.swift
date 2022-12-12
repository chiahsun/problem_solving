class Solution {
    func dfs(_ candidates: inout [Int], _ curPos: Int, _ leftVal: Int, _ cur: inout [Int], _ ans: inout [[Int]]) {
        if leftVal == 0 { 
            ans.append(cur)
            return
        }

        for i in curPos..<candidates.count {
            let c = candidates[i] 
            if leftVal - c >= 0  {
                cur.append(c)
                dfs(&candidates, i, leftVal - c, &cur, &ans)    
                cur.removeLast()                
            }
        }
    }
    
    func combinationSum(_ candidates: [Int], _ target: Int) -> [[Int]] {
        var candidates = candidates.sorted()
        
        var ans: [[Int]] = []
        var cur: [Int] = []
        dfs(&candidates, 0, target, &cur, &ans)
        return ans
    }
}