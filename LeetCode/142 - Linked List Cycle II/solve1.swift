/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *     }
 * }
 */

class Solution {
    func detectCycle(_ head: ListNode?) -> ListNode? {
        var p1 = head
        guard let head = head else { return nil }
        
        var p2 = head.next
        while p1 !== p2 && p2 != nil {
            p1 = p1?.next
            p2 = p2?.next?.next
        }
        if p2 == nil { return nil }
        
        var N = 1
        p2 = p1?.next
        while p2 !== p1 {
            p2 = p2?.next
            N += 1
        }
        
        (p1, p2) = (head, head)
        for _ in 0..<N {
            p2 = p2?.next
        }
        while p1 !== p2 {
            p1 = p1?.next
            p2 = p2?.next
        }
        
        return p1
    }
}