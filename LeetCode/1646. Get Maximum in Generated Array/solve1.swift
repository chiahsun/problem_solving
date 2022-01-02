class Solution {
    func getMaximumGenerated(_ n: Int) -> Int {
        guard n > 0 else { return 0 }
        var arr = Array(repeating: 0, count: n+1)
        arr[1] = 1
        var ans = 1
        for i in stride(from: 2, through: n, by: 1) {
            var cur = 0
            if i % 2 == 0 {
                cur = arr[i/2]
            } else {
                let prev = (i-1)/2
                cur = arr[prev] + arr[prev+1]
            }
            arr[i] = cur
            ans = max(ans, cur)
        }
        return ans
    }
}