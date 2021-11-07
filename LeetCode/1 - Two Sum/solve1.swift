class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var d: [Int: Int] = [:] 
        for i in nums.indices {
            let nowVal = nums[i]
            if let prev = d[target - nowVal] {
                return [prev, i]
            }
            d[nowVal] = i
        }
        return []
    }
}