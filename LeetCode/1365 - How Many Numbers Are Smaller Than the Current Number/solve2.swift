class Solution {
    func smallerNumbersThanCurrent(_ nums: [Int]) -> [Int] {
        var arr: [(Int, Int)] = []
        for i in 0..<nums.count {
            arr.append((nums[i], i))
        }
        arr.sort(by: { a, b in
            a.0 < b.0
        })

        var ans = Array(repeating: 0, count: nums.count)
        var numLess = 0
        var last = arr[0].0
        ans[arr[0].1] = numLess
        
        for i in 1..<arr.count {
            let cur = arr[i].0
            let pos = arr[i].1
            if cur == last {
                ans[pos] = numLess
            } else {
                last = cur
                numLess = i
                ans[pos] = numLess
            }
        }
        return ans
    }
}