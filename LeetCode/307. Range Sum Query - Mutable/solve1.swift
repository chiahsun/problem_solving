class RSNode {
    let l: Int
    let r: Int
    var sum: Int
    
    let lNode: RSNode?
    let rNode: RSNode?
    
    init(_ l: Int, _ r: Int, _ sum: Int, _ lNode: RSNode?, _ rNode: RSNode?) {
        self.l = l
        self.r = r
        self.sum = sum
        self.lNode = lNode
        self.rNode = rNode
    }
}

func dfs(_ nums: [Int], _ l: Int, _ r: Int) -> RSNode {
    if r == l+1 { return RSNode(l, r, nums[l], nil, nil) }
    let mid = (l+r+1)/2
    let lNode = dfs(nums, l, mid)
    var rNode: RSNode? = nil
    if r > mid { rNode = dfs(nums, mid, r) }
    let res = lNode.sum + (rNode?.sum ?? 0)
    return RSNode(l, r, res, lNode, rNode)
}

class NumArray {
    var root: RSNode

    init(_ nums: [Int]) {
        self.root = dfs(nums, 0, nums.count)
    }
    
    func update(_ index: Int, _ val: Int) {
        updateHelper(root, index, val)
    }
    
    func updateHelper(_ root: RSNode, _ index: Int, _ val: Int) -> Int {
        if root.lNode == nil && root.rNode == nil && root.l == index {
            root.sum = val
            return val
        }
        if index >= root.r || index < root.l { return root.sum }
        
        var lSum = 0
        var rSum = 0
        if let lNode = root.lNode { lSum = updateHelper(lNode, index, val) }
        if let rNode = root.rNode { rSum = updateHelper(rNode, index, val) }
        let res = lSum + rSum
        root.sum = res
        return res
    }
    
    func sumRange(_ left: Int, _ right: Int) -> Int {
        return dfsSumRange(left, right+1, root)
    }
    
    func dfsSumRange(_ l: Int, _ r: Int, _ root: RSNode) -> Int {
        if l <= root.l && root.r <= r {
            return root.sum
        }
        if l >= root.r || r < root.l { return 0 }
        var lSum = 0
        var rSum = 0
        if let lNode = root.lNode { lSum = dfsSumRange(l, r, lNode) }
        if let rNode = root.rNode { rSum = dfsSumRange(l, r, rNode) }
        return lSum + rSum
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * let obj = NumArray(nums)
 * obj.update(index, val)
 * let ret_2: Int = obj.sumRange(left, right)
 */