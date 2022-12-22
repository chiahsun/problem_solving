class Solution {
    func dfs(_ pos: Int, _ nums: [Int], _ cur: inout [Int], _ ans: inout [[Int]]) {
        if pos >= nums.count {
            ans.append(cur)
            return
        }
        
        dfs(pos+1, nums, &cur, &ans)
        cur.append(nums[pos])
        dfs(pos+1, nums, &cur, &ans)
        cur.removeLast()
    }
    
    func subsets(_ nums: [Int]) -> [[Int]] {
        var ans: [[Int]] = []
        var cur: [Int] = []
        dfs(0, nums, &cur, &ans)
        return ans
    }
}