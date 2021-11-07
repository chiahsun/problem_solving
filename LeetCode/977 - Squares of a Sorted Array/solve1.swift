class Solution {
    func findAbsMinIndex(_ nums: [Int]) -> Int {
        var minIndex = 0
        var minVal = square(nums[0])
        for i in nums.indices {
            if square(nums[i]) < minVal {
                minIndex = i
                minVal = square(nums[i])
            }
        }
        return minIndex
    }
    
    func square(_ x: Int) -> Int {
        return x*x
    }
    
    func sortedSquares(_ nums: [Int]) -> [Int] {
        let minIndex = findAbsMinIndex(nums)
        var ans: [Int] = [square(nums[minIndex])]
        var p1 = minIndex-1
        var p2 = minIndex+1
        while (p1 >= 0) || (p2 < nums.count) {
            if (p1 >= 0) && (p2 >= nums.count || square(nums[p1]) <= square(nums[p2])) {
                ans.append(square(nums[p1]))
                p1 -= 1
            } else {
                ans.append(square(nums[p2]))
                p2 += 1
            }
        }
        return ans
    }
}