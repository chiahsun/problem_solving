class Solution {
    func maxPoints(_ points: [[Int]]) -> Int {
        let N = points.count
        guard N >= 2 else { return 1 }
        
        var ans = 2
        for i in 0..<N {
            let center = points[i]
            // print("center: \(center)")
            var difference: [[Int]] = []
            for k in 0..<N where i != k {
                let another = points[k]
                difference.append([another[0]-center[0], another[1]-center[1]])
            }
            // print("Before:\n\(difference)")
            difference.sort(by: { 
                if $0[0] == 0 && $1[0] != 0 {
                    return false
                }
                if $0[0] != 0 && $1[0] == 0 {
                    return true
                }
                if $0[0] == 0 && $1[0] == 0 {
                    return $0[1] < $1[1]
                }
                return Double($0[1])/Double($0[0]) < Double($1[1])/Double($1[0])
            })
            // print("After:\n\(difference)")
            
            var count = 2
            var prev = difference[0]
            for k in 1..<difference.count {
                let cur = difference[k]
                let lhs = prev[0]*cur[1]
                let rhs = prev[1]*cur[0]
                // print("lhs: \(lhs) rhs: \(rhs)")
                if lhs == rhs {
                    if lhs != 0 {
                        count += 1
                    } else {
                        if prev[0] == 0 && cur[0] == 0 || prev[1] == 0 && cur[1] == 0 {
                            count += 1
                        } else {
                            count = 2
                            // print(" reset count to 2(0 case): \(cur)")
                        }
                    }
                } else {
                    count = 2
                    // print(" reset count to 2: \(cur)")
                }
                // print(" > count: \(count)")
                ans = max(ans, count)
                prev = cur
            }
        }
        return ans
    }
}