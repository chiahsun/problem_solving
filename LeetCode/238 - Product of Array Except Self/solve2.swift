class Solution {
    func productExceptSelf(_ nums: [Int]) -> [Int] {
        let N = nums.count
        var ans: [Int] = Array(repeating: 0, count: N)
        ans[N-1] = nums[N-1]
        for i in stride(from: N-2, to: 0, by: -1) {
            ans[i] = ans[i+1] * nums[i]
        }
        ans[0] = ans[1]
        var p = 1
        for i in 1..<N {
            p *= nums[i-1]
            ans[i] = p * (i+1 < N ? ans[i+1] : 1)
        }
        return ans
    }
}