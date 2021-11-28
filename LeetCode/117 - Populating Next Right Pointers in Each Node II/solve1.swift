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
        var head = root
        while let headExisted = head {
            var cur: Node? = headExisted
            var nextHead: Node? = nil
            var prev: Node? = nil
            while let curExisted = cur {
                if let left = curExisted.left {
                    prev?.next = left
                    prev = left
                    if nextHead == nil {
                        nextHead = left
                    }
                }
                if let right = curExisted.right {
                    prev?.next = right
                    prev = right
                    if nextHead == nil {
                        nextHead = right
                    }
                }
                cur = curExisted.next
            }
            head = nextHead
        }
        return root
    }
}