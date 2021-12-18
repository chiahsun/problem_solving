class Solution {
    func heightChecker(_ heights: [Int]) -> Int {
        var ans = 0
        var A = heights.sorted()
        for i in 0..<heights.count {
            if heights[i] != A[i] {
                ans += 1
            }
        }
        return ans
    }
}