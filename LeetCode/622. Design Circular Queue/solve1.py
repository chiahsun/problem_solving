class MyCircularQueue:

    def __init__(self, k: int):
        self.A = [0] * k
        self.head, self.sz = 0, 0

    def enQueue(self, value: int) -> bool:
        if self.sz == len(self.A):
            return False
        self.A[(self.head + self.sz) % len(self.A)] = value
        self.sz += 1
        return True

    def deQueue(self) -> bool:
        if self.sz == 0:
            return False
        self.head = (self.head + 1) % len(self.A)
        self.sz -= 1
        return True

    def Front(self) -> int:
        if self.sz == 0:
            return -1
        return self.A[self.head]
        
    def Rear(self) -> int:
        if self.sz == 0:
            return -1
        return self.A[(self.head + self.sz-1) % len(self.A)]
        
    def isEmpty(self) -> bool:
        return self.sz == 0
        
    def isFull(self) -> bool:
        return self.sz == len(self.A)
        


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()
