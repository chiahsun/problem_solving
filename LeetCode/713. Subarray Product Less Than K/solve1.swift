class Solution {
    func numSubarrayProductLessThanK(_ nums: [Int], _ k: Int) -> Int {
        var A: [Int] = []
        var acc = 1
        var ans = 0
        for x in nums {
            acc *= x
            A.append(x)
            if acc < k {
                ans += A.count
            } else {
                while acc >= k && !A.isEmpty {
                    let first = A.removeFirst()
                    acc /= first
                }
                ans += A.count
            }
        }
        return ans
    }
}