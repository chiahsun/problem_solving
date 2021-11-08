class Solution {
    func minCostClimbingStairs(_ cost: [Int]) -> Int {
        var cost = cost
        let N = cost.count
        for i in 2..<N {
            cost[i] += min(cost[i-1], cost[i-2])
        }
        return min(cost[N-1], cost[N-2])
    }
}