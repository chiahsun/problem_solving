/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init() { self.val = 0; self.next = nil; }
 *     public init(_ val: Int) { self.val = val; self.next = nil; }
 *     public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
 * }
 */
class Solution {
    func insertionSortList(_ head: ListNode?) -> ListNode? {
        guard let head = head else { return nil }
        
        var dummyHead = ListNode(0, head)
        var orderedTail = head
        
        while let tail = orderedTail.next {
            if tail.val < orderedTail.val {
                var p = dummyHead
                while let next = p.next {
                    if next.val > tail.val {
                        let tailNext = tail.next
                        p.next = tail
                        tail.next = next
                        orderedTail.next = tailNext
                        break
                    }
                    p = next
                }         
            } else {
                orderedTail = tail
            }
        }
        
        return dummyHead.next
    }
}