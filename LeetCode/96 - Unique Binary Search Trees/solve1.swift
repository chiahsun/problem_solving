class Solution {
    func numTrees(_ n: Int) -> Int {
        var ans = [1, 1, 2]
        for i in stride(from: 2, to: n, by: 1) {
            let cur = (0...i).reduce(0, { acc, k in
                return acc + ans[k] * ans[i-k]
            })
            ans.append(cur)
        }         
        return ans[n]
    }
}