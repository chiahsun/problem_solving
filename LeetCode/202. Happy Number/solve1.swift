class Solution {
    // 4
    // 16
    // 1+36=37
    // 9+49=58
    // 25+64=89
    // 64+81=145
    // 1+16+25=42
    // 16+4=20
    // 4
    
    // 7
    // 49
    // 16+81=97
    // 81+49=130
    // 1+9=10
    // 1
    
    func next(_ n: Int) -> Int {
        var a = n
        var res = 0
        while a > 0 {
            let digit = (a % 10)
            res += digit*digit
            a /= 10
        }
        return res
    }
    
    func isHappy(_ n: Int) -> Bool {
        var (a, b) = (n, next(n))
        while a != b && b != 1 {
            a = next(a)
            b = next(next(b))
        }
        
        return b == 1
    }
}