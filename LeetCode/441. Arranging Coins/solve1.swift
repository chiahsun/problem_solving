class Solution {
    func arrangeCoins(_ n: Int) -> Int {
        let doubled = Double(2*n)
        let x = Int(floor(doubled.squareRoot()))
        if n >= x*(x+1)/2 {
            return x
        }
        return x-1
    }
}