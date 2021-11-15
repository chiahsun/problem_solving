class Solution {
    func largestDivisibleSubset(_ nums: [Int]) -> [Int] {
        var A = nums.sorted()
        var dp = Array(repeating: 1, count: A.count)
        var prev = Array(repeating: -1, count: A.count)

        var maxCnt = 1
        var maxCntPos = 0
        for i in stride(from: 1, to: A.count, by: 1) {
            for k in 0..<i {
                if A[i] % A[k] == 0 {
                    if dp[k]+1 > dp[i] {
                        dp[i] = dp[k]+1
                        prev[i] = k
                    }
                    if dp[i] > maxCnt {
                        maxCnt = dp[i]
                        maxCntPos = i   
                    }    
                }
                
            }
        }
        
        var ans: [Int] = []
        var cur = maxCntPos
        while cur != -1 {
            ans.append(A[cur])
            cur = prev[cur]
        }
        
        return ans
    }
}