class Solution {
    func subtractProductAndSum(_ n: Int) -> Int {
        var x = n
        var product = 1
        var sum = 0
        while x > 0 {
            let digit = x % 10
            product *= digit
            sum += digit
            x /= 10
        }
        return product - sum
    }
}