
class NumArray {
    var rangeSum: [Int] = []

    init(_ nums: [Int]) {
        var prev = 0
        for a in nums {
            let cur = prev + a
            rangeSum.append(cur)
            prev = cur
        }
    }
    
    func sumRange(_ left: Int, _ right: Int) -> Int {
        return rangeSum[right] - (left > 0 ? rangeSum[left-1] : 0)
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * let obj = NumArray(nums)
 * let ret_1: Int = obj.sumRange(left, right)
 */