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
    let len: Int
    let head: ListNode?
    
    init(_ head: ListNode?) {
        self.head = head
        var l = 0
        if let head = head {
            l = 1
            var p = head
            while let next = p.next {
                p = next
                l += 1
            }
        }
        self.len = l
    }
    
    func getRandom() -> Int {
        guard let head = self.head else { return 0 }
        var l = len
        var p = head
        while let next = p.next, Int.random(in: 1...l) != 1 {
            p = next
            l -= 1
        }
        return p.val
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution(head)
 * let ret_1: Int = obj.getRandom()
 */