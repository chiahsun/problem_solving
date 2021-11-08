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
    func removeElements(_ head: ListNode?, _ val: Int) -> ListNode? {
        var dummy = ListNode(0)
        var p = dummy
        p.next = head
        while true {
            guard let pnext = p.next else { break }
           
            if pnext.val == val {
                p.next = pnext.next    
            } else {
                p = pnext
            }
        }
        return dummy.next
    }
}