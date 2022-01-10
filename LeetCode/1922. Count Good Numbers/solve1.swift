// 1: 0, 2, 4, 6, 8    -> 5
// 2: [[2,3,5,7]x5]    -> 20
// 3: [[0,2,4,6,8]x20] -> 100
// 4: [[2,3,5,7]x100]  -> 400
class Solution {
    func countGoodNumbers(_ n: Int) -> Int {
        // f(0) = 1, f(1) = 5, f(2) = 20, f(3) = 100
        // f(n) = 5*f(n-1) for n in odd
        // f(n) = 4*f(n-1) for n in even
        var res = 1
        switch n {
            case 0: 
                res = 1
            case let x where x % 4 == 1: 
                res = 5 * countGoodNumbers(x-1)
            case let x where x % 4 == 2: 
                res = 20 * countGoodNumbers(x-2)
            case let x where x % 4 == 3: 
                res = 100 * countGoodNumbers(x-3)
            default:
                let a = countGoodNumbers(n/2)
                res = a * a
        }
        return res % 1000000007
    }
}