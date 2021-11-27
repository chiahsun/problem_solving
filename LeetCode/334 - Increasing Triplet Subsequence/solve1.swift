class Solution {
    func increasingTriplet(_ nums: [Int]) -> Bool {
        var A: [Int] = []
        for x in nums {
            if A.isEmpty { A.append(x) }
            else if x < A[0] { A[0] = x }
            else if x == A[0] { }
            else if A.count == 1 { A.append(x) }
            else if A.count > 1 && x < A[1] { A[1] = x }
            else if A.count > 1 && x > A[1] { return true }
        }
        return false
    }
}