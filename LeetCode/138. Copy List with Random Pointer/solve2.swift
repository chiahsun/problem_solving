/**
 * Definition for a Node.
 * public class Node {
 *     public var val: Int
 *     public var next: Node?
 *     public var random: Node?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *    	   self.random = nil
 *     }
 * }
 */

class Solution {
    func copyRandomList(_ head: Node?) -> Node? {
        guard let head = head else { return nil }
        let newHead = Node(head.val)
        var p1 = head
        var p2 = newHead
        var m: [Node: Node] = [p1: p2]
        while let next = p1.next {
            let newNode = Node(next.val)
            p2.next = newNode
            p1 = next
            p2 = newNode
            m[p1] = p2
        }
        
        p1 = head; p2 = newHead
        while true {
            if let r = p1.random {
                p2.random = m[r]
            }
            if let p1Next = p1.next, let p2Next = p2.next {
                p1 = p1Next
                p2 = p2Next
            } else {
                break
            }
        }
        
        return newHead
    }
}