class STNode {
    var l: Int 
    var r: Int // inclusive
    var count: Int = 0
    
    var lNode: STNode? = nil
    var rNode: STNode? = nil
  
    init(_ l: Int, _ r: Int, _ lNode: STNode?, _ rNode: STNode?) { self.l = l; self.r = r; self.lNode = lNode; self.rNode = rNode }
}

func initialize(_ nums: [Int], _ begin: Int, _ end: Int) -> STNode {
    if begin == end {
        return STNode(nums[begin], nums[begin], nil, nil)
    }
    let mid = (begin+end)/2
    return STNode(nums[begin], nums[end], initialize(nums, begin, mid), initialize(nums, mid+1, end))
}

func incrementCount(_ root: STNode, _ val: Int) -> Int {
    // print("  > Call incrementCount \(val) at root \(root.l)...\(root.r) with childs \(root.lNode) \(root.rNode)")
    if val > root.r || val < root.l {
        return root.count
    }
    if root.lNode == nil && root.rNode == nil  {
        if root.l == val {
            root.count += 1
            // print("    > Increment \(root.l)...\(root.r) count to \(root.count)")     
        }
        return root.count
    } 
    
    if let lNode = root.lNode { incrementCount(lNode, val) }
    if let rNode = root.rNode { incrementCount(rNode, val) }
   
    root.count += 1
    // print("  > Update \(root.l)...\(root.r) count to \(root.count)")
    return root.count
}

func queryRange(_ root: STNode, _ l: Int, _ r: Int) -> Int {
    if l > root.r { return 0 }
    if r < root.l { return 0 }
    if l <= root.l && root.r <= r { return root.count }
    
    var lSum = 0
    var rSum = 0
    if let lNode = root.lNode { lSum = queryRange(lNode, l, r) }
    if let rNode = root.rNode { rSum = queryRange(rNode, l, r) }
    // print("  > Result: \(root.l)...\(root.r): \(lSum + rSum)")
    return lSum + rSum
}

class Solution {
    // [0(0)] 0
    // [0(1)] -2             query(0,4) -> 1
    // [0(1) 2(1)] 3         query(-5,-1) -> 0
    // [-3(1) 0(1) 2(1) ] 2  query(-4,0) -> 2
    
    // [0(1)] 0
    // [0(2)] -3
    // [0(2) 3(1)] -6             
    // [0(2) 3(1) 6(1)] -5
    // [0(2) 3(1) 5(1) 6(1)] -4
    // [0(2) 3(1) 4(1) 5(1) 6(1)] -2  -> 2
    
    // [0(0)] 0
    // [0(1)] -2
    // [0(1) 2(1)] -2
    // [0(1) 2(2)] -4
    // [0(1) 2(2) 4(1)] -7
    // [0(1) 2(2) 4(1) 7(1)] -5
    // [0(1) 2(2) 4(1) 5(1) 7(1)] -3       -> 1
    // [0(1) 2(2) 3(1) 4(1) 5(1) 7(1)] -2  -> 1
    // [0(1) 2(3) 3(1) 4(1) 5(1) 7(1)] -5 
    // [0(1) 2(3) 3(1) 4(1) 5(2) 7(1)] -1  query(5, 11) -> 3
    func countRangeSum(_ nums: [Int], _ lower: Int, _ upper: Int) -> Int {
        // print("nums count: \(nums.count)")
        var offset = 0
        var s: Set<Int> = []
        
        for cur in nums {
            offset += cur
            s.insert(cur-offset)
        }
        var boundaries = Array(s).sorted()
        var root = initialize(boundaries, 0, boundaries.count-1)
        // print("boundaries: \(boundaries)")
        
        offset = 0
        var ans = 0
        
        for cur in nums {
            offset += cur
            // print("Increment \(cur-offset) with offset \(offset)")
            incrementCount(root, cur-offset)
            // print("Query \(lower-offset)...\(upper-offset) at \(cur)")
            var tmp = queryRange(root, lower-offset, upper-offset)
            // print(" > \(tmp)")
            ans += tmp
        }
        return ans
    }
}