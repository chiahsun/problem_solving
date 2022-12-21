class ListNode {
    var val: Int
    var next: ListNode?
    init() { self.val = 0; self.next = nil; }
    init(_ val: Int) { self.val = val; self.next = nil; }
    init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
}

class Queue {
    var head: ListNode?
    var tail: ListNode?
    var count = 0
    
    var isEmpty: Bool { head == nil }
    
    func enqueue(_ x: Int) {
        count += 1
        if let tail = tail {
            tail.next = ListNode(x)
            self.tail = tail.next
        } else {
            head = ListNode(x)
            tail = head
        }
    }
    
    func dequeue() -> Int {
        if let head = head {
            count -= 1
            let val = head.val
            if tail === head {
                tail = nil
            }
            self.head = head.next
            return val
        }
        return 0
    }
}

    
class Solution {
    func minSubArrayLen(_ target: Int, _ nums: [Int]) -> Int {
        let N = nums.count
        var ans = N+1
        
        var A = Queue()
        var acc = 0
        for x in nums {
            acc += x
            A.enqueue(x)
            if acc >= target {
                repeat {
                    ans = min(ans, A.count)
                    if ans == 1 { return 1 }
                    let first = A.dequeue()
                    acc -= first
                } while acc >= target && !A.isEmpty
            }
        }
        
        return (ans > N) ? 0 : ans
    }
}