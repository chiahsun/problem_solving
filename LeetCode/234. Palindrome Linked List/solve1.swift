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
        
        var A: [Int] = [head.val]
        var p = head
        while let next = p.next {
            A.append(next.val)
            p = next
        }
        var (i, k) = (0, A.count-1)
        while i < k {
            if A[i] != A[k] { return false }
            i += 1
            k -= 1
        }
        
        return true
    }
}