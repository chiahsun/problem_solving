class Solution {
    func checkIfExist(_ arr: [Int]) -> Bool {
        var s: Set<Int> = Set(arr)
        var numZeros = 0
        for a in arr {
            if a == 0 {
                numZeros += 1
            }
            if a != 0 && s.contains(2 * a) {
                return true
            }
        }
        return numZeros >= 2
    }
}