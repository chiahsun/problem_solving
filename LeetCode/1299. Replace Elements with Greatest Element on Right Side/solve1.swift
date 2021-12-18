class Solution {
    func replaceElements(_ arr: [Int]) -> [Int] {
        var arr = arr
        let N = arr.count
        var prev = -1
        var prevEnd = N
        for i in stride(from: N-1, to: -1, by: -1) {
            let cur = arr[i]
            if cur > prev || i == 0 {
                for k in i..<prevEnd {
                    arr[k] = prev
                }
                prev = cur
                prevEnd = i
            }
        }
        return arr
    }
}