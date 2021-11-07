class Solution {
    func firstUniqChar(_ s: String) -> Int {
        var d: [Character: Int] = [:]
        for c in s {
            d[c, default: 0] += 1
        }
        for i in s.indices {
            if let cnt = d[s[i]], cnt == 1 {
                // https://stackoverflow.com/questions/34540185/how-to-convert-index-to-type-int-in-swift
                return s.distance(from: s.startIndex, to: i)
            }
        }
        return -1
    }
}