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
    func swapPairs(_ head: ListNode?) -> ListNode? {
        var dummyHead = ListNode(0, head)
        var p: ListNode? = dummyHead
        while p != nil {
            let next = p?.next
            let nextNext = next?.next
            let nextNextNext = nextNext?.next
            if nextNext != nil {
                nextNext?.next = next
                next?.next = nextNextNext
                p?.next = nextNext
            }
            p = next
        }
        return dummyHead.next
    }
}