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
    func mergeTwoLists(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var (l1, l2) = (l1, l2)
        var dummy = ListNode(0)
        var p: ListNode = dummy
        while l1 != nil || l2 != nil {
            if let p1 = l1, 
               l2 == nil || (l1!.val <= l2!.val) {
                p.next = l1
                l1 = l1!.next
            } else {
                p.next = l2
                l2 = l2!.next
            }
            p = p.next!
        }
        return dummy.next
    }
}