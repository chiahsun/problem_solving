class Solution {
    func findMaxConsecutiveOnes(_ nums: [Int]) -> Int {
        var ans = 0
        var cur = 0
        for a in nums {
            if a == 1 {
                cur += 1
            } else {
                cur = 0
            }
            ans = max(ans, cur)
        }
        return ans
    }
}