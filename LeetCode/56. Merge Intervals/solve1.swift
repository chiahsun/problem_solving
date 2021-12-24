class Solution {
    func merge(_ intervals: [[Int]]) -> [[Int]] {
        var A = intervals.sorted { $0[0] < $1[0] }
        var interval = A[0]
        var ans: [[Int]] = []
        for i in 1..<A.count {
            let cur = A[i]
            if cur[0] <= interval[1] {
                interval[1] = max(interval[1], cur[1])
            } else {
                ans.append(interval)
                interval = cur
            }
        }
        ans.append(interval)
        
        return ans
    }
}