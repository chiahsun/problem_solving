class Solution {
    func rob(_ nums: [Int]) -> Int {
        let N = nums.count
        if N == 1 { return nums[0] }
        
        var A = Array(repeating: 0, count: N)
        var B = Array(repeating: 0, count: N)
        
        (A[0], A[1]) = (nums[0], nums[0]) // left is picked
        (B[0], B[1]) = (0, nums[1])

        for i in stride(from: 2, to: N, by: 1) {
            let x = nums[i]
            A[i] = (i == N-1) ? A[i-1] : max(A[i-2] + x, A[i-1])       
            B[i] = max(B[i-2] + x, B[i-1])
        }
        
        return max(A[N-1], B[N-1])
    }
}