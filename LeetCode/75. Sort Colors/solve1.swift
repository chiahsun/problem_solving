class Solution {
    func sortColors(_ nums: inout [Int]) {
        var (n0, n1, n2) = (0, 0, 0)
        for x in nums {
            switch x {
                case 0: n0 += 1
                case 1: n1 += 1
                case 2: n2 += 1
                default: break
            }
        }
        for i in 0..<n0 { nums[i] = 0 }
        for i in n0..<n0+n1 { nums[i] = 1 }
        for i in n0+n1..<n0+n1+n2 { nums[i] = 2 }
    }
}