/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init() { self.val = 0; self.left = nil; self.right = nil; }
 *     public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
 *     public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
 *         self.val = val
 *         self.left = left
 *         self.right = right
 *     }
 * }
 */
class BSTIterator {
    var st: [TreeNode] = []
    
    init(_ root: TreeNode?) {
        var cur = root
        while let curNode = cur {
            st.append(curNode)
            cur = curNode.left
        }
    }
    
    func next() -> Int {
        let res = st.last!.val
        var oldLast = st.removeLast()
        if let right = oldLast.right {
            st.append(right)
            var p = right
            while let left = p.left {
                st.append(left)
                p = left
            }
        }
        
        return res
    }
    
    func hasNext() -> Bool {
        !st.isEmpty
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * let obj = BSTIterator(root)
 * let ret_1: Int = obj.next()
 * let ret_2: Bool = obj.hasNext()
 */