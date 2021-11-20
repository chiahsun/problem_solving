class Solution {
    func majorityElement(_ nums: [Int]) -> Int {
        var ans = nums[0]
        var cnt = 1
        let N = nums.count
        
        for i in 1..<N {
            let x = nums[i]
            if cnt == 0 { 
                ans = x 
                cnt = 1
            } else {
                if x == ans { cnt += 1 }
                else        { cnt -= 1 }
            }
            if cnt >= N-i-1 {
                break
            }
        }
        return ans
    }
}