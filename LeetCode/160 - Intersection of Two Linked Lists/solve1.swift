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
    func getLength(_ head: ListNode?) -> Int {
        var p = head
        var len = 0
        while p != nil {
            len += 1
            p = p?.next
        }
        return len
    }
    
    func getIntersectionNode(_ headA: ListNode?, _ headB: ListNode?) -> ListNode? {
        let L1 = getLength(headA)
        let L2 = getLength(headB)
        
        var (p1, p2) = (headA, headB)
        if L1 > L2 {
            for _ in 0..<(L1-L2) { p1 = p1?.next }
        } else {
            for _ in 0..<(L2-L1) { p2 = p2?.next }
        }
        while p1 !== p2 {
            p1 = p1?.next
            p2 = p2?.next
        }
        return p1
    }
}