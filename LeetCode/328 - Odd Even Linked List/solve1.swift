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
// 1 -> 2 -> 3 -> 4 -> 5
// 1 -> 3 -> 4 -> 5
// 2
class Solution {
    func oddEvenList(_ head: ListNode?) -> ListNode? {
        guard let oddHead = head else { return nil }
        guard let evenHead = oddHead.next else { return head }
        oddHead.next = evenHead.next
        evenHead.next = nil
        
        var oddCur = oddHead
        var evenCur = evenHead
        while let p = oddCur.next {
            if let evenNode = p.next { 
                evenCur.next = evenNode
                evenCur = evenNode
                p.next = evenNode.next
                evenNode.next = nil
            }
            oddCur = p
        }
        oddCur.next = evenHead
        return oddHead
    }
}