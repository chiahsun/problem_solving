class Solution {
    func maxPower(_ s: String) -> Int {
        var pos = s.startIndex
        var head = Character("?")
        var cnt = 1
        var maxCnt = cnt
        while pos != s.endIndex {
            let cur = s[pos]
            if cur == head {
                cnt += 1
                maxCnt = max(maxCnt, cnt)
            } else {
                head = cur
                cnt = 1
            }
            pos = s.index(after: pos)
        }
        return maxCnt
    }
}