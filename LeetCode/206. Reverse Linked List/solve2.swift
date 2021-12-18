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
    func reverseList(_ head: ListNode?) -> ListNode? {
        guard let headE = head else { return nil }
        
        var head = headE
        var p = head
        while let next = p.next {
            p.next = next.next
            var oldHead = head
            head = next
            head.next = oldHead
        }
        return head
    }
}