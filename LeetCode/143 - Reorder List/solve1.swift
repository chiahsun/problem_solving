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

// 1 2 3 4
// 1 4 2 3

// 1 2 3 4 5
// 1 5 2 3 4
// 1 5 2 4 3
class Solution {

    func reorder(_ head: inout ListNode, _ cur: ListNode) -> Bool {
        if let next = cur.next, reorder(&head, next) {
            return true
        } 
        guard let oriNext = head.next else { return true }
     
        head.next = cur
        cur.next = oriNext
        head = oriNext
            
        if let newNext = head.next {
            if newNext === cur {
                head.next = nil
                return true
            }
            if let newNextNext = newNext.next, newNextNext === cur {
                newNext.next = nil
                return true
            } 
        } 

        return false
    }
    
    func reorderList(_ head: ListNode?) {
        guard let head = head else { return }
        var p = head
        reorder(&p, p)
    }
}