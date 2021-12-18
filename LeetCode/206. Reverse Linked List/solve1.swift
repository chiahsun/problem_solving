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
        guard var p1 = head else { return nil }
        var p2 = p1.next
        p1.next = nil

        while let p2NotNil = p2 {
            (p1, p2, p2NotNil.next) = (p2NotNil, p2NotNil.next, p1)
        }
        return p1
    }
}