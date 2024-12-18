// Implement a limit size min heap
// https://en.wikipedia.org/wiki/Min-max_heap
class MinHeap {
    var A: [Int]
    var N = 0
    let maxSize: Int 
    
    init(_ sz: Int) { 
        self.maxSize = sz
        A = Array(repeating: 0, count: sz+1) 
    }
    
    //    0
    //  1   2
    // 3 4 5 6
    func insert(_ a: Int) {
        var pos = N
        N += 1
        A[pos] = a
        while case let parent = (pos-1)/2, parent >= 0 && A[parent] > A[pos] {
            (A[parent], A[pos]) = (A[pos], A[parent])
            pos = parent
        }
        if N > maxSize {
            popMin()
        }
    }
    
    func popMin() -> Int {
        let minVal = A[0] 
        N -= 1
        if N == 0 { 
            return minVal
        }
        (A[0], A[N]) = (A[N], A[0])
        
        var pos = 0
        while case let leftIndex = 2*pos+1, leftIndex < N {
            let rightIndex = leftIndex+1
            let lessVal = min(A[leftIndex], rightIndex < N ? A[rightIndex] : Int.max)
            if lessVal < A[pos] {
                let lessIndex = (lessVal == A[leftIndex]) ? leftIndex : rightIndex
                (A[pos], A[lessIndex]) = (A[lessIndex], A[pos])
                pos = lessIndex
            } else {
                break
            }
        }
        return minVal
    }
}

class Solution {
    func findKthLargest(_ nums: [Int], _ k: Int) -> Int {
        var hp = MinHeap(k)
        for a in nums {
            hp.insert(a)
        }
        return hp.popMin()
    }
}