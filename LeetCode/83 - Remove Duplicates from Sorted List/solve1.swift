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
        guard let theHead = head else { return nil }
        var p = theHead
        while let pnext = p.next {
            if p.val == pnext.val {
                p.next = pnext.next
            } else {
                p = pnext
            }
        }
        return theHead
    }
}