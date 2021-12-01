class ListNode {
    var val: Int
    var next: ListNode?
    var prev: ListNode?
    init(_ val: Int) { self.val = val }
    init(_ val: Int, _ next: ListNode, _ prev: ListNode) { self.val = val; self.next = next; self.prev = prev }
}

class CircularList {
    var first: ListNode
    var size: Int
    
    // We deal with N >= 2 only
    init(_ N: Int) {
        self.first = ListNode(1)
        var prev = self.first
        for i in 1..<N {
            let cur = ListNode(i+1)
            prev.next = cur
            cur.prev = prev
            prev = cur
        }
        prev.next = first  
        first.prev = prev
        size = N
    }
    
    var firstNode: ListNode {
        get {
            return first
        }
    }
    
    func remove(_ start: ListNode, _ k: Int) -> ListNode {
        let k = (k-1) % size
        var p = start
        for _ in stride(from: 0, to: k, by: 1) {
            p = p.next!
        }
        let res = p.next!
        self.size -= 1
        p.prev!.next = p.next!
        p.next!.prev = p.prev!
        if p === firstNode {
            self.first = res
        }
        return res
    }
}

class Solution {
    func findTheWinner(_ n: Int, _ k: Int) -> Int {
        guard n > 1 else { return 1 }
        
        var cl = CircularList(n)
        var p = cl.firstNode
        while cl.size > 1 {
            p = cl.remove(p, k)
        }
        return cl.firstNode.val
    }
}