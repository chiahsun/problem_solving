class BinaryIndexedTree {
    var A: [Int]
    
    init(_ N: Int) { A = Array(repeating: 0, count: N+1) }
    
    func add(_ pos: Int, _ val: Int) {
        var pos = pos+1
        while pos < A.count {
            A[pos] += val
            pos = pos + (pos & (-pos))
        }
    }
    
    func get(_ pos: Int) -> Int {
        var pos = pos+1
        var total = 0
        while pos > 0 {
            total += A[pos]
            pos = (pos & (pos-1))
        }
        return total
    }
}

class NumArray {

    var t: BinaryIndexedTree
    init(_ nums: [Int]) {
        t = BinaryIndexedTree(nums.count)
        for i in 0..<nums.count {
            t.add(i, nums[i])
        }
    }
    
    func sumRange(_ left: Int, _ right: Int) -> Int {
        return t.get(right) - (left > 0 ? t.get(left-1) : 0)
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * let obj = NumArray(nums)
 * let ret_1: Int = obj.sumRange(left, right)
 */