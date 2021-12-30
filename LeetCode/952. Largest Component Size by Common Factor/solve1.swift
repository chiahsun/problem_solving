//   4   6  15  35
// 2x2 2x3 3x5 5x7
//   1   2   2   2

// 2 -> 4 6
// 3 -> 6 15
// 5 -> 15 35

// 1 3 15 35
// 1 1 5 35
// 1 1 1 7
// 1 1 1 1

func getDivisor(_ a: Int) -> Int {
    guard a > 1 else { return a }
    if a % 2 == 0 { return 2 }
    var d = 3
    while d*d <= a {
        if a % d == 0 { return d }
        d += 2
    }
    return a
}

class Solution {
    func largestComponentSize(_ nums: [Int]) -> Int {
        let M = nums.max()!+1
        let N = nums.count
        var s = Array(repeating: 0, count: M)
        var numToPos = Array(repeating: -1, count: M)
        for i in 0..<N {
            let cur = nums[i]
            s[cur] = cur
            numToPos[cur] = i
        }
        
        var used = Array(repeating: false, count: N)
        var ans = 1
        
        for headPos in 0..<used.count where !used[headPos] {
            var q: [Int] = [headPos]
            var curCnt = 0
            func addCount(_ curPos: Int) {
                used[curPos] = true
                curCnt += 1 
                ans = max(ans, curCnt)
            }
            while let pos = q.popLast() {
                let cur = s[nums[pos]]
                let p = getDivisor(cur)
                if p > 1 {
                    for m in stride(from: p, to: M, by: p) where s[m] > 1 {
                        while s[m] > 1 && s[m] % p == 0 {
                            s[m] /= p
                        }
                        let pos = numToPos[m]
                        if s[m] > 1 {
                            q.append(pos)
                        } else { // We add count when s[i] becomes 1
                            addCount(pos)
                        }
                    }
                }      
            }     
        }
       
        return ans
    }
}