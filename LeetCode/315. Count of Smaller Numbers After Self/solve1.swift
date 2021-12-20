class STNode {
    let l: Int
    let r: Int // inclusive
    var count: Int
    
    let left: STNode?
    let right: STNode?
    
    init(_ l: Int, _ r: Int, _ count: Int, _ left: STNode?, _ right: STNode?) {
        self.l = l
        self.r = r
        self.count = count
        self.left = left
        self.right = right
    }
}

func initialize(_ nums: [Int], _ l: Int, _ r: Int) -> STNode {
    if l == r { return STNode(nums[l], nums[l], 0, nil, nil) }
    
    let mid = (l+r)/2
    return STNode(nums[l], nums[r], 0, initialize(nums, l, mid), initialize(nums, mid+1, r))
}

func incrementCount(_ root: STNode, _ val: Int) -> Int {
    if root.l == root.r && root.l == val { 
        root.count += 1
        return root.count
    }
    if root.l > val { return root.count }
    if root.r < val { return root.count }
    
    var lSum = incrementCount(root.left!, val)
    var rSum = 0
    if let right = root.right { rSum = incrementCount(right, val) }
    root.count = lSum + rSum
    return root.count
}

func queryBelow(_ root: STNode, _ val: Int) -> Int {
    if root.l >= val { return 0 }
    if root.r < val { return root.count }
    var lSum = queryBelow(root.left!, val)
    var rSum = 0
    if let right = root.right { rSum = queryBelow(right, val) }
    return lSum + rSum
}

class Solution {
    func countSmaller(_ nums: [Int]) -> [Int] {
        var sortedNums = Array(Set(nums)).sorted()
        var root = initialize(sortedNums, 0, sortedNums.count-1)
        var ans: [Int] = []
        for a in nums.reversed() {
            incrementCount(root, a)
            ans.append(queryBelow(root, a))
        }

        return ans.reversed()
    }
}