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
    func deleteDuplicates(_ head: ListNode?) -> ListNode? {
        var dummy = ListNode(0, head)
        
        var prev = dummy
        while let cur = prev.next {
            if let next = cur.next, cur.val == next.val {
                let valToRemove = cur.val
                var newNext: ListNode? = next
                while let newNextExisted = newNext, newNextExisted.val == valToRemove {
                    newNext = newNextExisted.next
                }
                prev.next = newNext
            } else {
                prev = cur
            }
        }
        
        return dummy.next
    }
}