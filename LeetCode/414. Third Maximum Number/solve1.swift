class Solution {
    func thirdMax(_ nums: [Int]) -> Int {
        var A: [Int] = []
        for x in nums {
            var pos = 0
            while pos<A.count {
                if x > A[pos] { break }
                else if x == A[pos] { pos = -1; break }
                pos += 1
            }
            if pos >= 0 {
                A.insert(x, at: pos)
            }
            if A.count > 3 { A.removeLast() }
        }
        return A.count >= 3 ? A[2] : A[0]
    }
}