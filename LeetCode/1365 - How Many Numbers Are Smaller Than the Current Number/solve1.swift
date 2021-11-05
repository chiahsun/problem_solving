class Solution {
    func smallerNumbersThanCurrent(_ nums: [Int]) -> [Int] {
        var ans: [Int] = []
        for i in 0..<nums.count {
            let cur = nums[i]
            var cnt = 0
            for k in 0..<nums.count {
                if nums[k] < cur && i != k{
                    cnt += 1
                }
            }
            ans.append(cnt)
        }
        return ans
    }
}