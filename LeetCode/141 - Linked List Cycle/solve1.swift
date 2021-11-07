/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *     }
 * }
 */

class Solution {
    func hasCycle(_ head: ListNode?) -> Bool {
        if head == nil || head!.next == nil { return false }
        var p1 = head
        var p2 = head!.next
        while p2 != nil {
            if (p1 === p2) {
                return true
            }
            if (p2!.next == nil || p2!.next!.next == nil) { return false }
            p2 = p2!.next!.next
            p1 = p1!.next
          
        }
        return false
    }
}