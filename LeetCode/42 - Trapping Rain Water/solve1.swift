class Solution {
    //
    //           +
    // + @ @ @ @ +
    // + @ @ + @ +
    // + + @ + + +
    // + + @ + + +
    func trap(_ height: [Int]) -> Int {
        let N = height.count
        var l = Array(repeating: 0, count: N)
        var r = Array(repeating: 0, count: N)
        
        l[0] = height[0]
        r[N-1] = height[N-1]
        for i in stride(from: 1, to: N, by: 1) {
            l[i] = max(height[i], l[i-1])
            r[N-i-1] = max(height[N-i-1], r[N-i])
        }
        
        var ans = 0
        for i in stride(from: 1, to: N-1, by: 1) {
            ans += (min(l[i], r[i]) - height[i])
        }
        return ans
    }
}