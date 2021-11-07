class Solution {
    func generate(_ numRows: Int) -> [[Int]] {
        var ans = [[1]]

        for i in 1..<numRows {
            let lastRow = ans[i-1]
            var curRow: [Int] = Array(repeating: 1, count: i+1)
            for k in 1..<i {
                curRow[k] = lastRow[k-1] + lastRow[k]
            }
            ans.append(curRow)
        }
        return ans
    }
}