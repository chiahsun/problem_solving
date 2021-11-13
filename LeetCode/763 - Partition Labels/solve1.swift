class Solution {
    func partitionLabels(_ s: String) -> [Int] {
        let characters = Array(s)
        var d: [Character: Int] = [:]
        for i in 0..<s.count {
            d[characters[i]] = i
        }
        
        var ans: [Int] = []
        var start = 0
        while start < characters.count {
            var i = start
            var end = d[characters[i]]!+1
            while i < end {
                end = max(end, d[characters[i]]!+1)
                i += 1
            }
            ans.append(end-start)
            start = end
        }
        return ans
    }
}