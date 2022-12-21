class Solution {
    func minSubArrayLen(_ target: Int, _ nums: [Int]) -> Int {
        let N = nums.count
        var ans = N+1
        
        var A: [Int] = []
        var acc = 0
        for x in nums {
            acc += x
            A.append(x)
            if acc >= target {
                repeat {
                    ans = min(ans, A.count)
                    let first = A.removeFirst()
                    acc -= first
                } while acc >= target && !A.isEmpty
            }
        }
        
        return (ans > N) ? 0 : ans
    }
}