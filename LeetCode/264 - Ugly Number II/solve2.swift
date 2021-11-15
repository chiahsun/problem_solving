class Solution {
    func nthUglyNumber(_ n: Int) -> Int {
        var A = [1]
        var (i2, i3, i5) = (0, 0, 0)
         while A.count < n {
            let (v2, v3, v5) = (A[i2] * 2, A[i3] * 3, A[i5] * 5)
            let minVal = min(v2, v3, v5)
            switch minVal {
                case v2: i2 += 1
                case v3: i3 += 1
                case v5: i5 += 1
                default: break
            }
            if minVal > A.last! {
                A.append(minVal)
            }
        }
        
        return A.last!
    }
}