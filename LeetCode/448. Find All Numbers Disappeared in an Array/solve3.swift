class Solution {
    func findDisappearedNumbers(_ nums: [Int]) -> [Int] {
        var nums = nums.sorted()
        var i = 1
        var ans: [Int] = []
        var pos = 0
        // 1 2 2 3 3 4 7 8
        // 1 2 3 4 5 6 7 8
        while pos < nums.count {
            let cur = nums[pos]
            if cur == i {
                pos += 1
                i += 1
            } else if cur < i {
                pos += 1
            } else {
                while i < cur {
                    ans.append(i)
                    i += 1
                }
            }
        }
        while i <= nums.count {
            ans.append(i)
            i += 1
        }
        return ans
    }
}