class ListNode {
    var next: ListNode?
    var prev: ListNode?
    let val: Int
    init(_ val: Int) { self.val = val }
}

class MyLinkedList {
    var head: ListNode? = nil
    var tail: ListNode? = nil
    var size = 0
    
    init() { }
    
    func get(_ index: Int) -> Int {
        var p = head
        for i in 0..<index {
            p = p?.next
        }
        if let p = p { return p.val }
        return -1
    }
    
    func addAtHead(_ val: Int) {
        var newNode = ListNode(val)
        if let h = head {
            newNode.next = h
            h.prev = newNode
            head = newNode
        } else {
            head = newNode
            tail = newNode
        }
        size += 1
    }
    
    func addAtTail(_ val: Int) {
        var newNode = ListNode(val)
        if let t = tail {
            t.next = newNode
            newNode.prev = t
            tail = newNode
        } else {
            head = newNode
            tail = newNode
        }
        size += 1
    }
    
    func addAtIndex(_ index: Int, _ val: Int) {
        if index >= size {
            if index == size { addAtTail(val) }
            return
        }
        if index == 0 {
            addAtHead(val)
            return
        }

        var p = head
        for i in 0..<index {
            p = p?.next
        }
        var newNode = ListNode(val)
        newNode.prev = p?.prev
        newNode.next = p
        p?.prev?.next = newNode
        p?.prev = newNode
        size += 1
    }
    
    func deleteAtIndex(_ index: Int) {
        if index >= size { return }
        if index == 0 { 
            head = head?.next 
            if let h = head { h.prev = nil }
            size -= 1
            if size == 0 { tail = nil }
            return
        }
        if index == size-1 {
            tail = tail?.prev
            if let t = tail { t.next = nil }
            size -= 1
            if size == 0 { head = nil }
            return
        }
        var p = head
        for i in 0..<index {
            p = p?.next
        }
        p?.prev?.next = p?.next
        p?.next?.prev = p?.prev
        size -= 1
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * let obj = MyLinkedList()
 * let ret_1: Int = obj.get(index)
 * obj.addAtHead(val)
 * obj.addAtTail(val)
 * obj.addAtIndex(index, val)
 * obj.deleteAtIndex(index)
 */