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
    func removeNthFromEnd(_ head: ListNode?, _ n: Int) -> ListNode? {
        var dummy = ListNode(0)
        dummy.next = head
        var pprev: ListNode? = dummy
        var pfirst = head
        var pend = head
        for i in 0..<n {
            pend = pend?.next
        }
        while pend != nil {
            pprev = pprev?.next
            pfirst = pfirst?.next
            pend = pend?.next
        }
        pprev!.next = pfirst?.next
        return dummy.next
    }
}