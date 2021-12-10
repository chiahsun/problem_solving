// X X = = X
// X = = X X
class Solution {
    func numTilings(_ n: Int) -> Int {
        // +  
        // +
        // a a   a b
        // b b   a b
        var F = [0, 1, 2]
        // + +
        // +
        var U = [0, 0, 1]
        // +
        // + +
        // var D = [0, 0, 1] // same as U
        
        let mod = 1000000007
        for i in stride(from: 3, to: n+1, by: 1) {
            let a = (F[i-1] + F[i-2] + 2 * U[i-1]) % mod
            let b = (U[i-1] + F[i-2]) % mod
            F.append(a)
            U.append(b)
        }
        return F[n]
    }
}