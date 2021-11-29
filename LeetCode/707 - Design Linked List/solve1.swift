class ListNode {
    let val: Int
    var next: ListNode?
    init(_ val: Int) { self.val = val }
    init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next }
}

class MyLinkedList {
    var head: ListNode?
    var tail: ListNode?
    
    init() { }
    
    func get(_ index: Int) -> Int {
        var p = head
        for _ in 0..<index {
            p = p?.next
        }
        guard let p = p else { return -1 }
        return p.val
    }
    
    func addAtHead(_ val: Int) {
        let newHead = ListNode(val, head)
        if tail == nil { tail = newHead }
        self.head = newHead
    }
    
    func addAtTail(_ val: Int) {
        guard let tail = tail else {
            head = ListNode(val)
            tail = head
            return
        }

        tail.next = ListNode(val)
        self.tail = tail.next
    }
    
    func addAtIndex(_ index: Int, _ val: Int) {
        var dummyHead = ListNode(0, head)
        var p: ListNode? = dummyHead
        for _ in 0..<index {
            p = p?.next
        }
        guard let p = p else { return }
        
        let ori = p.next
        let newNode = ListNode(val)
        p.next = newNode
        newNode.next = ori
        if index == 0 { self.head = dummyHead.next }
        if tail == nil { self.tail = self.head }
        if ori == nil { self.tail = newNode }
    }
    
    func deleteAtIndex(_ index: Int) {
        var dummyHead = ListNode(0, head)
        var p: ListNode? = dummyHead
        for _ in 0..<index {
            p = p?.next
        }
        guard let p = p else { return }
        p.next = p.next?.next
        if p.next == nil { tail = p }
        if index == 0 { self.head = dummyHead.next }
    }
}
// [1, 2, 7, 0]
// [1, 2, 0]
// [6, 1, 2, 0]
// [6, 1, 2, 0, 4]
//         -> 4

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * let obj = MyLinkedList()
 * let ret_1: Int = obj.get(index)
 * obj.addAtHead(val)
 * obj.addAtTail(val)
 * obj.addAtIndex(index, val)
 * obj.deleteAtIndex(index)
 */