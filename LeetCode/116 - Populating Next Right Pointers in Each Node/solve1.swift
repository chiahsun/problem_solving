/**
 * Definition for a Node.
 * public class Node {
 *     public var val: Int
 *     public var left: Node?
 *     public var right: Node?
 *	   public var next: Node?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *         self.next = nil
 *     }
 * }
 */

class Solution {
    func connect(_ root: Node?) -> Node? {
        
        var q: [Node] = []
        if let root = root { q.append(root) }
        
        while !q.isEmpty {
            var nextq: [Node] = []
            
            var p = q.removeFirst()
            if let left = p.left { nextq.append(left) }
            if let right = p.right { nextq.append(right) }
            while !q.isEmpty {
                var next = q.removeFirst()
                p.next = next
                p = next
                if let left = p.left { nextq.append(left) }
                if let right = p.right { nextq.append(right) }
            } 
            q = nextq
        }
        
        return root
    }
}