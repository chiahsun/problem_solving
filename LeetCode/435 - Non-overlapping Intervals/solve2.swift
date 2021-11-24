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
        let intervals = intervals.sorted { $0[1] < $1[1] }

        var ans = 0
        var prevEnd = -50000
        for x in intervals {
            if x[0] < prevEnd {
                ans += 1
            } else {
                prevEnd = x[1]
            }
        }
        return ans
    }
}