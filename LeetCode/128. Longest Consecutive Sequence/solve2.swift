class UFNode {
    let val: Int
    var parent: UFNode?
    var count = 1
    
    init(_ val: Int) { self.val = val }
        
    func makeUnion(_ another: UFNode) -> Int {
        var ra = findRoot()
        var rb = another.findRoot()
        if ra !== rb {
            ra.parent = rb
            rb.count += ra.count           
        }
        return rb.count
    }
    
    func findRoot() -> UFNode {
        var p = self
        guard var parent = p.parent else { return self }
        while let grandParent = parent.parent {
            p.parent = grandParent
            (p, parent) = (parent, grandParent)
        }
        return parent
    }
}

class Solution {
    func longestConsecutive(_ nums: [Int]) -> Int {
        guard !nums.isEmpty else { return 0 }
        var m: [Int: UFNode] = [:]
        for a in nums where m[a] == nil { 
            m[a] = UFNode(a)
        }
        var ans = 1
        for a in nums {
            let cur = m[a]!
            if let mapped = m[a+1] { ans = max(ans, mapped.makeUnion(cur)) }
            if let mapped = m[a-1] { ans = max(ans, mapped.makeUnion(cur)) }
        }
        return ans
    }
}