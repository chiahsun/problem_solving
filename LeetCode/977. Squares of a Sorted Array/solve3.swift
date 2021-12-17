func square(_ a: Int) -> Int { a * a }

class Solution {
    func sortedSquares(_ nums: [Int]) -> [Int] {
        var minIndex = 0
        for i in 1..<nums.count {
            if abs(nums[i]) <= abs(nums[i-1]) {
                minIndex = i
            } else {
                break
            }
        }
        
        var ans: [Int] = [square(nums[minIndex])]
        var (i, k) = (minIndex+1, minIndex-1)
        let N = nums.count
        while i < N || k >= 0 {
            if k < 0 {
                ans.append(square(nums[i]))
                i += 1
            } else if i >= N {
                ans.append(square(nums[k]))
                k -= 1
            } else {
                let a = square(nums[i])
                let b = square(nums[k])
                if b < a {
                     ans.append(b)
                    k -= 1
                } else {
                    ans.append(a)
                    i += 1
                }
            }
        }
        
        return ans
    }
}