class Solution {
    func minCostToMoveChips(_ position: [Int]) -> Int {
        var nEven = 0
        var nOdd = 0
        position.forEach {
            if $0 % 2 == 0 {
                nEven += 1
            } else {
                nOdd += 1
            }
        } 
        return min(nEven, nOdd)
    }
}