// https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
class Solution {
    let nums: [Int]
    
    init(_ nums: [Int]) {
        self.nums = nums
    }
    
    func reset() -> [Int] {
        return nums
    }
    
    func shuffle() -> [Int] {
        let N = nums.count
        var res = nums
        for i in 0..<(N-1) {
            res.swapAt(i, Int.random(in: i..<N))
        }
        return res
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution(nums)
 * let ret_1: [Int] = obj.reset()
 * let ret_2: [Int] = obj.shuffle()
 */