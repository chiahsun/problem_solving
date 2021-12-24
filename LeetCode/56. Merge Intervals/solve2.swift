class Solution {
    func merge(_ intervals: [[Int]]) -> [[Int]] {
        let intervals = intervals.sorted(by: { $0[0] < $1[0] })
        var ans: [[Int]] = []
        var prevStart = intervals[0][0]
        var prevEnd = intervals[0][1]
        for i in 1..<intervals.count {
            let interval = intervals[i]
            let (start, end) = (interval[0], interval[1])
            if start <= prevEnd {
                prevEnd = max(prevEnd, end)
            } else {
                ans.append([prevStart, prevEnd])
                prevStart = start
                prevEnd = end
            }
        }
        ans.append([prevStart, prevEnd])
        return ans
    }
}