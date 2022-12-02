class MyLinkedList:
    class ListNode:
        def __init__(self, val=0, next=None):
            self.val = val
            self.next = next

    def __init__(self):
        self.dummyHead = ListNode()
        self.tail = self.dummyHead

    def get(self, index: int) -> int:
        p = self.dummyHead
        for _ in range(index+1):
            p = p.next
            if p is None:
                return -1
        return p.val

    def debug_print(self, fn):
        p = self.dummyHead
        print(fn, end=": ")
        while p.next:
            print(p.next.val, end=" ")
            p = p.next
        print(" tail: ", self.tail.val)

    def addAtHead(self, val: int) -> None:
        old_next = self.dummyHead.next
        self.dummyHead.next = ListNode(val=val, next=old_next)
        if self.tail == self.dummyHead:
            self.tail = self.dummyHead.next
        # self.debug_print('addAtHead')
        
    def addAtTail(self, val: int) -> None:
        self.tail.next = ListNode(val=val)
        self.tail = self.tail.next
        # self.debug_print('addAtTail')

    def addAtIndex(self, index: int, val: int) -> None:
        p = self.dummyHead
        for _ in range(index):
            p = p.next
            if p is None:
                return
        old_next = p.next
        p.next = ListNode(val=val, next=old_next)
        if p.next.next is None:
            self.tail = p.next
        #self.debug_print('addAtIndex')

    def deleteAtIndex(self, index: int) -> None:
        p = self.dummyHead
        for _ in range(index):
            p = p.next
            if p is None or p.next is None:
                return
        p.next = p.next.next
        if p.next is None:
            self.tail = p
        # self.debug_print('deleteAtIndex')
        
# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
