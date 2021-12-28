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
    func middleNode(_ head: ListNode?) -> ListNode? {
        guard let head = head else { return nil }
        guard let headNext = head.next else { return head }
        var pSlow = head
        var pFast = headNext
        while let pFastNext = pFast.next, 
              let pFastNextNext = pFastNext.next, 
              let pSlowNext = pSlow.next {
            pFast = pFastNextNext
            pSlow = pSlowNext
        }
        return pSlow.next 
    }
}