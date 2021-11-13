class Solution {
    func minimumTotal(_ triangle: [[Int]]) -> Int {
        var now = [triangle[0][0]]
        for i in stride(from: 1, to: triangle.count, by: 1) {            
            var next = [now[0]+triangle[i][0]]
    
            for k in stride(from: 0, to: i-1, by: 1) {
                next.append(min(now[k], now[k+1]) + triangle[i][k+1])
            }
            next.append(now.last! + triangle[i].last!)
            now = next
        }
        return now.min()!
    }
}