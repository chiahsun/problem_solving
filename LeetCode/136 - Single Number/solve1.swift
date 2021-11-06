class Solution {
    func singleNumber(_ nums: [Int]) -> Int {
        return nums.reduce(0, { acc, elem in
            return acc ^ elem
        })
    }
}