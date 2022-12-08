class Solution {
    func rob(_ nums: [Int]) -> Int {
        var A: [Int] = [nums[0]]
        var B: [Int] = [0]
        for i in 1..<nums.count {
            A.append(B[i-1] + nums[i])
            B.append(max(A[i-1], B[i-1]))
        }
        return max(A[nums.count-1], B[nums.count-1])
    }
    //     2 1 1 2
    // A: [2 1 3 3]
    // B: [0 2 2 4]
}