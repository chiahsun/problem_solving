/**
 * Definition for a Node.
 * public class Node {
 *     public var val: Int
 *     public var prev: Node?
 *     public var next: Node?
 *     public var child: Node?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.prev = nil
 *         self.next = nil
 *         self.child  = nil
 *     }
 * }
 */

class Solution {
    func flatten(_ head: Node?) -> Node? {
        guard let head = head else { return nil }
        var dummyHead = Node(0)
        var st: [Node] = [head]
        var p = dummyHead
        while let top = st.popLast() {
            p.next = top
            top.prev = p
            p = top
            while true {
                if let child = p.child { 
                    if let next = p.next {
                        st.append(next)     
                    }
                    p.next = child
                    p.child = nil
                    child.prev = p
                    p = child
                } else {
                    if let next = p.next {
                        p = next
                    } else {
                        break
                    }                    
                }
            }
        }
        dummyHead.next?.prev = nil
        return dummyHead.next
    }
}