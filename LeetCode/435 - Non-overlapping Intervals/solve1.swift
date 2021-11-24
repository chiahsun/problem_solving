class Solution {
    // |----------|
    //     |--||----|
    
    // |--- | |---|
    //      |---||---|
    
    // |---|
    //   |---|
    //     |---|
    //       |---|
    //         |---|
    // Whenever there is overlapping, we remove the one that has greater end.
    func eraseOverlapIntervals(_ intervals: [[Int]]) -> Int {
        let intervals = intervals.sorted { $0[0] < $1[0] || ($0[0] == $1[0] && $0[1] < $1[1]) }

        var ans = 0
        var prev = intervals[0]
        for i in 1..<intervals.count {
            let cur = intervals[i]
            let begin = max(prev[0], cur[0])
            let end = min(prev[1], cur[1])
            if end > begin {
                if prev[1] > cur[1] {
                    prev = cur
                } else {
                }
                ans += 1
            } else {
                prev = cur
            }
        }
        return ans
    }
}