class Solution {
    func generate(_ numRows: Int) -> [[Int]] {
        var ans = [[1]]

        for i in 1..<numRows {
            let lastRow = ans.last!
            var curRow: [Int] = []
            for k in 0...i {
                if k == 0 || k == i { 
                    curRow.append(1)
                } else {
                    curRow.append(lastRow[k-1] + lastRow[k])
                }
            }
            ans.append(curRow)
        }
        return ans
    }
}