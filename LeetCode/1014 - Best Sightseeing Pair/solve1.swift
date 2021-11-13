class Solution {
    func maxScoreSightseeingPair(_ values: [Int]) -> Int {
        var ans = values[0] + values[1] - 1
        var prev = max(values[0]-2, values[1]-1)
        for i in 2..<values.count {
            let x = values[i]
            ans = max(x+prev, ans)
            prev = max(x, prev)
            prev -= 1
        }
        return ans
    }
}