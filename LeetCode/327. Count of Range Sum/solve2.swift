class BinaryIndexedTree {
    var A: [Int]
    
    init(_ N: Int) { A = Array(repeating: 0, count: N+1) }
    
    func add(_ pos: Int, _ val: Int) {
        var pos = pos+1
        while pos < A.count {
            A[pos] += val
            pos += (pos & -pos)
        }
    }
    
    func get(_ pos: Int) -> Int {
        var pos = pos+1
        var total = 0
        while pos > 0 {
            total += A[pos]
            pos &= (pos-1)
        }
        return total
    }
}

func binarySearchLeq(_ A: [Int], _ target: Int, _ strictLess: Bool) -> Int {
    guard let first = A.first else { return -1 }
    var i = 0
    if let last = A.last, last <= target { i = A.count-1  }
    else if first == target { i = 0 }
    else if first > target { return -1 }
    else {
        var k = A.count-1
        while i < k {
            let mid = (i+k+1)/2
            let midVal = A[mid]
            if midVal == target { i = mid; break }
            if midVal > target { k = mid-1 }
            else               { i = mid }
        }
    }
    
    if strictLess && i >= 0 && A[i] == target {
        return i - 1
    }
    return i
}

// [0(0)]
// [0(1)] -2            -> query(0, 4)     1
// [0(1) 2(1)] 3        -> query(-5, -1)   0
// [-3(1) 0(1) 2(1)] 2  -> query(-4, 0)    2
class Solution {
    func countRangeSum(_ nums: [Int], _ lower: Int, _ upper: Int) -> Int {
        var s: Set<Int> = []
        var offset = 0
        for a in nums {
            offset += a
            s.insert(a-offset)
        }
        var A = Array(s).sorted()
        
        var ans = 0
        offset = 0
        var t = BinaryIndexedTree(A.count)
        for a in nums {
            offset += a
            let cur = a - offset
            let pos = binarySearchLeq(A, cur, false)
            t.add(pos, 1)
            let lPos = binarySearchLeq(A, lower - offset, true)
            let rPos = binarySearchLeq(A, upper - offset, false)
            let lCount = lPos < 0 ? 0 : t.get(lPos)
            let rCount = rPos < 0 ? 0 : t.get(rPos)
            ans += (rCount - lCount)
        }
        return ans
    }
}