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
        while let next = p1.next {
            let newNode = Node(next.val)
            p2.next = newNode
            p1 = next
            p2 = newNode
        }
        
        p1 = head; p2 = newHead
        while true {
            var rp1 = head
            var rp2 = newHead
            if let r = p1.random {
                while true {
                    if rp1 === r {
                        p2.random = rp2
                        break
                    }
                    rp1 = rp1.next!
                    rp2 = rp2.next!
                }   
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