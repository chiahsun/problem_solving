class Solution {
    func maxDistToClosest(_ seats: [Int]) -> Int {
        var ans = 1
        var prev = 0
        let N = seats.count
        for i in 0..<N where seats[i] == 1 { 
            ans = max(ans, i) 
            prev = i
            break
        }
        var end = prev
        for i in (prev+1)..<N where seats[i] == 1 {
            ans = max(ans, (i - prev)/2)
            prev = i
            end = i
        }
        ans = max(ans, N-1-end)
        return ans
    }
}