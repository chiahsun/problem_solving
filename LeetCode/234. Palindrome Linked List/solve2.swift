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
    func isPalindrome(_ head: ListNode?) -> Bool {
        guard let head = head else { return true }
        guard let headNext = head.next else { return true }
        if headNext.next == nil { return head.val == headNext.val }
        
        var dummyHead = ListNode(0, head)
        var (p1, p2) = (dummyHead, dummyHead)
        while let p1Next = p1.next {
            // print("p1: \(p1.val) p2: \(p2.val)")
            if let p2NextNext = p2.next?.next, let p2NextNextNext = p2NextNext.next {
                p1 = p1Next
                p2 = p2NextNext
            } else {
                p2 = p1Next.next!
                break
            }
        }
        // print("p2: \(p2.val)")
        var anotherHead: ListNode? = nil
        while let p2Next = p2.next {
            p2.next = anotherHead
            anotherHead = p2
            p2 = p2Next
        }
        p2.next = anotherHead
        p1 = head
        while p1.val == p2.val {
            if let p1Next = p1.next, let p2Next = p2.next {
                p1 = p1Next; p2 = p2Next
            } else {
                return true
            }
        }
        
        return false
        
    }
}