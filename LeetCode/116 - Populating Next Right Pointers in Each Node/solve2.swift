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
        guard var root = root else { return nil }
        var first: Node = root
        
        while true {
            var cur = first
            var prevRight: Node? = nil
            while true {
                prevRight?.next = cur.left
                cur.left?.next = cur.right    
                prevRight = cur.right
                guard let next = cur.next else { break }
                cur = next
            }
            guard let newFirst = first.left else { break }
            first = newFirst
        }
        
        return root
    }
}