class Solution {
    func dfs(_ K: Int, _ startValue: Int, _ leftValue: Int, _ cur: inout [Int], _ ans: inout [[Int]]) {
        for i in stride(from: startValue, to: min(leftValue+1, 10), by: 1) {
            let newLeftValue = leftValue - i
            cur.append(i)
            if newLeftValue == 0 {
                if cur.count == K {
                    ans.append(cur)
                }
            } else if cur.count < K {
                dfs(K, i+1, newLeftValue, &cur, &ans)   
            }
            cur.removeLast()
        }
    }
    
    func combinationSum3(_ k: Int, _ n: Int) -> [[Int]] {
        var cur: [Int] = []
        var ans: [[Int]] = []
        dfs(k, 1, n, &cur, &ans)
        return ans
    }
}