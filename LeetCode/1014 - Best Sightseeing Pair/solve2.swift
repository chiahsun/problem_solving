class Solution {
    func maxScoreSightseeingPair(_ values: [Int]) -> Int {
        var prev = 0
        var ans = 0
        for x in values {
            ans = max(x+prev, ans)
            prev = max(x, prev)
            prev -= 1
        }
        return ans
    }
}