class Solution {
    func duplicateZeros(_ arr: inout [Int]) {
        var numZeros = arr.reduce(0, { acc, elem in 
            return acc + (elem == 0 ? 1 : 0)
        })
        let N = arr.count
        for i in stride(from: N-1, to: -1, by: -1) {
            let cur = arr[i]
            if cur == 0 {
                if i+numZeros < N { arr[i+numZeros] = 0 }
                if i+numZeros-1 < N { arr[i+numZeros-1] = 0 }
                numZeros -= 1
            } else {
                if i+numZeros < N { arr[i+numZeros] = cur }
            }
        }
        
    }
}