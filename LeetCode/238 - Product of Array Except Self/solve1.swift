class Solution {
    func productExceptSelf(_ nums: [Int]) -> [Int] {
        let N = nums.count
        var P: [Int] = Array(repeating: 0, count: N)
        var S: [Int] = Array(repeating: 0, count: N)
        var ans: [Int] = Array(repeating: 0, count: N)
        
        P[0] = nums[0]
        S[N-1] = nums[N-1]
        for i in 1..<N {
            P[i] = P[i-1] * nums[i]
        }
        for i in stride(from: N-2, to: -1, by: -1) {
            S[i] = S[i+1] * nums[i]
        }
        for i in 0..<N {
            ans[i] = (i > 0 ? P[i-1] : 1) * (i+1 < N ? S[i+1] : 1)
        }
        return ans
    }
}