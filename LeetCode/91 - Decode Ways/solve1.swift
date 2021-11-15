class Solution {
    func numDecodings(_ s: String) -> Int {
        let characters = Array(s)
        let N = characters.count
        if characters[0] == "0" {
            return 0
        }
        
        var dp = Array(repeating: 0, count: N)
        dp[0] = 1
        
        for i in 1..<N {
            let length1 = characters[i]
            let ans1 = (length1 == "0") ? 0 : dp[i-1]
            
            let length2 = String([characters[i-1], characters[i]])
            var ans2 = 0
            switch length2 {
                case "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26":
                    ans2 = (i > 2) ? dp[i-2] : 1
                default:
                    break
            }
            dp[i] = ans1 + ans2
        }
        
        return dp.last!
    }
}