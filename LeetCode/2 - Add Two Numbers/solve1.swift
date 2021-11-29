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
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var (p1, p2) = (l1, l2)
        var carry = 0
        var dummy = ListNode(0)
        var cur = dummy
        while p1 != nil || p2 != nil || carry > 0 {
            carry += (p1?.val ?? 0)
            carry += (p2?.val ?? 0)
            let next = ListNode(carry % 10)
            cur.next = next
            cur = next
            p1 = p1?.next
            p2 = p2?.next
            carry /= 10
        }
        return dummy.next
    }
}