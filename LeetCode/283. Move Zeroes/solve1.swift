class Solution {
    func swap(_ nums: inout [Int], _ i: Int, _ k: Int) {
        nums[i] ^= nums[k]
        nums[k] ^= nums[i]
        nums[i] ^= nums[k]
    }
    
    func moveZeroes(_ nums: inout [Int]) {
        guard let firstZeroIndex = nums.firstIndex(where: { $0 == 0 }) else {
            return
        }
        
        var p0 = firstZeroIndex
        for i in firstZeroIndex+1..<nums.count {
            if nums[i] != 0 {
                swap(&nums, p0, i)
                p0 += 1
            }
        }   
    }
}