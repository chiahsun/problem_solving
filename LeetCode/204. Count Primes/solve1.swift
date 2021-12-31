class Solution {
    func countPrimes(_ n: Int) -> Int {
        guard n > 2 else { return 0 }
        var s = Array(repeating: true, count: n)
        var ans = 1
        var last = 0
        var i = 3
        while i*i <= (n-1) {
            if s[i] {
                ans += 1
                for k in stride(from: i*i, to: n, by: i) {
                    s[k] = false
                }    
            }
            i += 2
        }
            
        for k in stride(from: i, to: n, by: 2) where s[k] {
            ans += 1
        }
        return ans
    }   
}