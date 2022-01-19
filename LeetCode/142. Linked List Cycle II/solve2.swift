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
    func detectCycle(_ head: ListNode?) -> ListNode? {
        guard let head = head else { return nil }
        
        var pSlow = head, pFast = head
        if pFast.next?.next == nil { return nil }
        pFast = pFast.next!.next!
        pSlow = pSlow.next!
        while pFast !== pSlow, let pFastNext = pFast.next, let pFastNextNext = pFastNext.next, let pSlowNext = pSlow.next {
            pFast = pFastNextNext
            pSlow = pSlowNext
        }
        if pFast !== pSlow { return nil }
        
        var p = head
        while p !== pSlow, let pNext = p.next,  let pSlowNext = pSlow.next {
            p = pNext
            pSlow = pSlowNext
        }
        return p
    }
}