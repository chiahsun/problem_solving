// k = 2
// 1 2 3 4 5 6 7
// 1 1 3 1 3 5 8 
// 8 9 10 11 12 13 14 15 
// 1 3  5  7  9 11 13 15
// 16
//  1

// Let N = 2^a+b. Then, ans = 2*b+1

// f(1, k) = 1
// f(N, k) = f(N-1,k)+k (minus enough N to <= N)

// f(1, 2) = 1
// f(2, 2) = 1+2 - 2 = 1
// f(3, 2) = 1+2 = 3
// f(4, 2) = 3+2 - 4 = 1
// f(5, 2) = 1+2 = 3

// f(1, 5) = 1
// f(2, 5) = 1+5 -2-2 = 2
// f(3, 5) = 2+5 -3-3 = 1
// f(4, 5) = 1+5 - 4 = 2
// f(5, 5) = 2+5 - 5 = 2
// f(6, 5) = 2+5 - 6 = 1
class Solution {
    func findTheWinner(_ n: Int, _ k: Int) -> Int {
        var ans = 1
        for N in 2..<(n+1) {
            ans = (ans + k) % N
            ans = (ans == 0) ? N : ans
        }
        return ans
    }
}