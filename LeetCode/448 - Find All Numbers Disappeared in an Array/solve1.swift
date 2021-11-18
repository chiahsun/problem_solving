class Solution {
    func findDisappearedNumbers(_ nums: [Int]) -> [Int] {
        var d = Set(nums)
        
        var ans: [Int] = []
        for i in 1...nums.count {
            if !d.contains(i) {
                ans.append(i)
            }
        }
        return ans
    }
}