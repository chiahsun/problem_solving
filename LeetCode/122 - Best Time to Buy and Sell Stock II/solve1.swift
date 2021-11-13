class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        var a = 10000
        var b = 10000
        var ans = 0
        for x in prices {
            if b > a {
                if x > b { b = x }
                else { 
                    ans += (b - a) 
                    a = x
                    b = x
                }
            } else {
                if x > a { b = x }
                else { a = x; b = x }
            }
        }
        ans += (b - a)
        return ans
    }
}