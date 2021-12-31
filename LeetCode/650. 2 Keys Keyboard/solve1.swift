// 2(2)
// 1->2 (Copy 1 Paste 1)(2)

// 3(3)
// 2(Copied: 1 Copy: 1) (1)

// 4(4)
// 2(2)
// 2 + 2(2)

// 5(5)
// 1(0)
// 1+(1+1+1+1) (Copy 1 paste 4) (5)

// 6(5)
// 2(2)
// 2 + 2 + 2(Copy: 1 paste 2) (3)

// 8(6)
// 2x4 4x2
// 2 + 2 + 2 + 2(Copied: 2(2) Copy:1 Paste: 3) (6)
// 4 + 4 (Copied: 4(4) Copy:1 Paste: 1) (6)

// 12(6)
// 1x12(12)
// 2x6
// 2 + 2 + 2 + 2 + 2 + 2(Copied: 2(2) Copy: 1 Paste 5)(8)
// 3x4
// 3 + 3 + 3 + 3(Copied: 3(3) Copy: 1 Paste 3)(7)
// 4x3
// 4 + 4 + 4(Copied: 4(4) Copy: 1 Paste 2)(7)
// 6x2
// 6 + 6(Copied: 6(5) Copy: 1 Paste 1)(7)
class Solution {
    func minSteps(_ n: Int) -> Int {
        var A = Array(repeating: 0, count: n+1)
        func compute(_ n: Int) -> Int {
            if n < 2 { return 0 }
            if A[n] != 0 { return A[n] }
            var p = 2
            var res = n
            while p*p <= n {
                if n % p == 0 {
                    let other = n/p
                    res = min(res, compute(p) + other)
                    if other != p {
                        res = min(res, compute(other) + p)
                    }
                }
                p += 1
            }
            A[n] = res
            return res
        }
        compute(n)
        return A[n]
    }
}