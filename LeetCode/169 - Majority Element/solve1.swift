class Solution {
    func majorityElement(_ nums: [Int]) -> Int {
        var ans = 0
        var cnt = 0
        for x in nums {
            if cnt == 0 { 
                ans = x 
                cnt = 1
            } else {
                if x == ans { cnt += 1 }
                else        { cnt -= 1 }
            }
        }
        return ans
    }
}