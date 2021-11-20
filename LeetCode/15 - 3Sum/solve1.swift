class Solution {
    func threeSum(_ nums: [Int]) -> [[Int]] {
        let A = nums.sorted()
        let N = A.count
        var d: [Int: [Int]] = [:]
        for i in 0..<N {
            d[A[i], default: []].append(i)
        }
        
        var ans: [[Int]] = []
        var i = 0
        while i < N-2 {
            let a = A[i]
            var k = i+1
            while k < N-1 {
                let b = A[k]
                let target = -a-b
                if let others = d[target],
                   case let filtered = others.filter { $0 > k },
                   !filtered.isEmpty {
                    ans.append([a, b, target])
                }
                while k < N-1 && A[k] == b { k += 1 }
                
            }
            while i < N-2 && A[i] == a { i += 1 }
        }
        
        return ans
    }
}