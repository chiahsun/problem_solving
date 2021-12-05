class Node {
    let val: Int
    var count = 1
    init(_ val: Int) { self.val = val }
}

class MaxHeap {
    // We compare by count
    var A: [Node] = []
    var valueToPos: [Int: Int] = [:]
    
    //    0
    //  1   2
    // 3 4
    func increment(_ value: Int) {
        if let pos = valueToPos[value] {
            var pos = pos
            A[pos].count += 1
            while case let parent = (pos-1)/2, parent >= 0 && A[parent].count < A[pos].count {
                swap(parent, pos)
                pos = parent
            }
        } else {
            valueToPos[value] = A.count
            A.append(Node(value))
        }
    }
    
    func swap(_ i1: Int, _ i2: Int) {
        assert(i1 < A.count)
        assert(i2 < A.count)
        let (i1Value, i2Value) = (A[i1].val, A[i2].val)
        (A[i1], A[i2]) = (A[i2], A[i1])
        (valueToPos[i1Value], valueToPos[i2Value]) = (valueToPos[i2Value], valueToPos[i1Value])
    }
    
    func pop() -> Int {
        if valueToPos.isEmpty { return -1 }
        let maxVal = A[0].val
        if valueToPos.count == 1 {
            A.removeLast()
            valueToPos.removeAll()
            return maxVal
        }
        
        let N = A.count
        swap(0, N-1)
        A.removeLast()
        valueToPos.removeValue(forKey: maxVal)

        var pos = 0
        while true {
            let leftIndex = 2*pos+1
            let rightIndex = 2*pos+2
            if leftIndex < A.count {
                let leftCount = A[leftIndex].count
                let rightCount = (rightIndex < A.count) ? (A[rightIndex].count) : 0
                let moreCount = max(leftCount, rightCount)
                if moreCount > A[pos].count {
                    let moreIndex = (moreCount == leftCount) ? leftIndex : rightIndex
                    swap(pos, moreIndex)
                    pos = moreIndex
                } else {
                    break
                }
            } else {
                break
            }
        }
        return maxVal
    }
}

class Solution {
    func topKFrequent(_ nums: [Int], _ k: Int) -> [Int] {
        var mp = MaxHeap()
        nums.forEach { mp.increment($0) }
        return (0..<k).map { $0; return mp.pop() }
    }
}