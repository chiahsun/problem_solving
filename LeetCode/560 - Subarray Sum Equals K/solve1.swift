class Solution {
    func subarraySum(_ nums: [Int], _ k: Int) -> Int {
        let target = k
        let N = nums.count
        var A = Array(repeating: 0, count: N+1)
        for i in 0..<N {
            A[i+1] = A[i] + nums[i]
        }
        var ans = 0
        for i in 0..<N {
            for k in i+1..<(N+1) where A[k] - A[i] == target {
                ans += 1
            }
        }
        return ans
    }
}