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
    func rotateRight(_ head: ListNode?, _ k: Int) -> ListNode? {
        guard let head = head else { return nil }
        var N = 1
        var p = head
        while let next = p.next {
            p = next
            N += 1
        }
        let K = N - (k % N)
        if K == N { return head }
        p = head
        for i in 1..<K {
            p = p.next!
        }
        let newHead = p.next!
        p.next = nil
        p = newHead
        while let next = p.next {
            p = next
        }
        p.next = head
        return newHead
    }
}