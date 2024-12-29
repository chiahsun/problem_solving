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
    func reverseKGroup(_ head: ListNode?, _ k: Int) -> ListNode? {
        var dummyHead = ListNode(0, head)
        var cur = dummyHead
        while let groupHead = cur.next {
            var p = groupHead
            var group: [ListNode] = []
            for _ in 0..<k {
                group.append(p)    
                if let next = p.next {
                    p = next
                } else {
                    break
                }
            }
            if group.count == k {
                let groupEnd = group.last!.next
                group = group.reversed()
                var prev: ListNode? = nil
                for n in group {
                    prev?.next = n
                    prev = n
                }
                cur.next = group[0]
                group.last!.next = groupEnd
            } else {
                break
            }
            cur = group.last!
        }
        return dummyHead.next
    }
}