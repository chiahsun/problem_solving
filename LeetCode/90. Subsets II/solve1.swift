class Solution {
    func dfs(_ pos: Int, _ nums: [Int], _ cur: inout [Int], _ ans: inout [[Int]]) {
        if pos >= nums.count {
            ans.append(cur)
            return
        }
        
        var nextPos = pos+1
        while nextPos < nums.count && nums[nextPos] == nums[pos] {
            nextPos += 1
        }
        dfs(nextPos, nums, &cur, &ans)
        
        cur.append(nums[pos])
        dfs(pos+1, nums, &cur, &ans)
        cur.removeLast()
    }
    
    func subsetsWithDup(_ nums: [Int]) -> [[Int]] {
        let nums = nums.sorted()
        
        var cur: [Int] = []
        var ans: [[Int]] = []
        dfs(0, nums, &cur, &ans)
        return ans
    }
}