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
    func dfs(_ p1: ListNode, _ p2: ListNode, _ st: inout [ListNode]) {
        st.append(p2)
        if let p2Next = p2.next, let p1Next = p1.next {
            dfs(p1Next, p2Next, &st)
        } else {
            st = st.reversed()    
        }
        var oldNext = p1.next
        var first = st.removeLast()
        p1.next = first
        first.next = oldNext
    }
    
    func reorderList(_ head: ListNode?) {
        guard let head = head, let headNext = head.next else { return }
 
        var pSlow = head
        var pFast = headNext
        var tail = head
        
        while true {
            if let pFastNext = pFast.next {
                if let pFastNextNext = pFastNext.next {
                    pFast = pFastNextNext
                    pSlow = pSlow.next!
                } else {
                    tail = pSlow.next!
                    break
                }
            } else {
                tail = pSlow
                break
            }
        }
        
        var st: [ListNode] = []
        var p2 = tail.next!
        tail.next = nil
        dfs(head, p2, &st)
    }
}