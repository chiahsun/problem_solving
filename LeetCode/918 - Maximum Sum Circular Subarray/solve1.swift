class Solution {
    func maxSubarraySumCircular(_ nums: [Int]) -> Int {
        let N = nums.count
        var A = Array(repeating: 0, count: N)
        var B = Array(repeating: 0, count: N)
        var C = Array(repeating: 0, count: N)
        var prevA = nums[N-1]
        var prevC = prevA
        A[N-1] = prevA
        C[N-1] = prevC
        for i in stride(from: N-2, to: -1, by: -1) {
            prevA += nums[i]
            A[i] = max(A[i+1], prevA)
            C[i] = max(nums[i], nums[i]+prevC)
            prevC = C[i]
        }
        
        var prevB = nums[0]
        B[0] = prevB
        for i in 1..<B.count {
            prevB += nums[i]
            B[i] = max(B[i-1], prevB)
        }
        // print("A: \(A)")
        // print("B: \(B)")
        // print("C: \(C)")
        var ans = nums[0]
        for i in 1..<A.count {
            ans = max(ans, A[i]+B[i-1], A[i], B[i-1], C[i])
        }
        return ans
    }
}