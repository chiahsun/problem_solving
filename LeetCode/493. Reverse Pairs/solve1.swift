// 3 2 1
//     1

// ---
// 3 2 1 query(6+1)
// 1   1    


// ---
// 3 2(2) 1 query(4+1)
// 1      1   

// ---
// 3 2(2) 1 query(6+1)
// 2      1   

// ---
// 3 2(2) 1 query(2+1)
// 2      2   

// We use the binary indexed tree with decreasing sequence

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
            pos &= pos-1
        }
        return total
    }
}

// Find pos of the least element >= target
func binarySearch(_ nums: [Int], _ target: Int) -> Int {
    guard let first = nums.first, target <= first else { return -1 }
    if first == target { return 0 }
    if let last = nums.last, last >= target { return nums.count-1 }
    
    var i = 0
    var k = nums.count-1
    while i < k {
        let mid = (i+k+1)/2
        let midVal = nums[mid]
        
        if midVal == target { i = mid; break }
        
        if midVal < target {
            k = mid-1
        } else {
            i = mid
        }
    }
    return i
}

class Solution {
    func reversePairs(_ nums: [Int]) -> Int {
        var sortedSequence = Array(Set(nums)).sorted(by: >)

        var t = BinaryIndexedTree(sortedSequence.count)
        var ans = 0
        for a in nums {
            var pos = binarySearch(sortedSequence, 2*a+1)
            if pos >= 0 {
                ans += t.get(pos)
            }
            pos = binarySearch(sortedSequence, a)
            t.add(pos, 1)
        }
        return ans
    }
}