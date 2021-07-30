class Solution {
    func buildArray(_ nums: [Int]) -> [Int] {
        var ans = [Int]()
        for i in nums.indices {
            ans.append(nums[nums[i]])
        }
        return ans
    }
}
