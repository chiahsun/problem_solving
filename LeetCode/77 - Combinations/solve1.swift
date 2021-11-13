class Solution {
    func take(_ now: inout [Int], _ A: inout [Int], _ startPos: Int,  _ left: Int, _ ans: inout [[Int]]) {
        if left == 0 {
            ans.append(now)
            return
        }
        for i in startPos..<A.count-left+1  {
            let a = A[i]
            now.append(a)
            take(&now, &A, i+1, left-1, &ans)
            now.removeLast()            
        }
    }
    
    func combine(_ n: Int, _ k: Int) -> [[Int]] {
        var ans: [[Int]] = []
        var all: [Int] = []
        for i in 1...n {
            all.append(i)
        }
        var start: [Int] = []
        take(&start, &all, 0, k, &ans)
        return ans
    }
}