class Solution {
    func dfs(_ cur: Int, _ nums: inout [Int], _ ans: inout [[Int]]) {
        if cur == nums.count-1 {
            ans.append(nums)
            return
        }
        
        var s = Set<Int>()
        for i in cur..<nums.count where !s.contains(nums[i]) {
            s.insert(nums[i])
            (nums[cur], nums[i]) = (nums[i], nums[cur])
            dfs(cur+1, &nums, &ans)
            (nums[cur], nums[i]) = (nums[i], nums[cur])
        }
    }
    
    func permuteUnique(_ nums: [Int]) -> [[Int]] {
        var nums = nums
        
        var ans: [[Int]] = []
        dfs(0, &nums, &ans)
        return ans
    }
}