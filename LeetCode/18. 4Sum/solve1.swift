class Solution {
    // 0 1 2 3 4 5
    // ^            a
    //     ^        b
    //       ^   ^  (target - a - b) 2sum with limited range
    // n^2 * nlog(n)
    
    // [2 2 2 3 3 3], target = 10
    func fourSum(_ nums: [Int], _ target: Int) -> [[Int]] {
        let N = nums.count
        guard N >= 4 else { return [] }
        
        let nums = nums.sorted()
        var ans: [[Int]] = []
        
        for i in 0..<(N-3) {
            if i > 0 && nums[i] == nums[i-1] { continue }
            for k in (i+1)..<(N-2) {
                if k != i+1 && nums[k] == nums[k-1] { continue }
                let anotherTarget = target - nums[i] - nums[k]
                twoSum(nums, k+1, anotherTarget, nums[i], nums[k], &ans)
            }
        }
        return ans
    }
    
    func twoSum(_ nums: [Int], _ begin: Int, _ target: Int, _ a: Int, _ b: Int, _ ans: inout [[Int]]) {
        let N = nums.count
        for i in begin..<(N-1) {
            if i != begin && nums[i] == nums[i-1] { continue }
            let c = nums[i]
            let d = target - c
            if binarySearch(nums, i+1, d) > 0 {
                ans.append([a, b, c, d])
            }
        }
    }
    
    func binarySearch(_ nums: [Int], _ begin: Int, _ target: Int) -> Int {
        var i = begin
        var k = nums.count-1
        if target < nums[i] || target > nums[k]  { return -1 }
        while i < k {
            let mid = (i+k)/2
            let midVal = nums[mid]
            if midVal == target { return mid }
            if midVal > target { k = mid }
            else               { i = mid+1 }
        }
        return (nums[i] == target) ? i : -1
    }
}