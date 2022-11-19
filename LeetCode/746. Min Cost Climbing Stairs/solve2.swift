class Solution {
    func minCostClimbingStairs(_ cost: [Int]) -> Int {
        var (a, b) = (cost[1], cost[0])
        for i in 2..<cost.count {
            (a, b) = (cost[i] + min(a, b), a)
        }
        return min(a, b)
    }
}