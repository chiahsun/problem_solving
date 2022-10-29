class MyQueue:

    def __init__(self):
        self.s1, self.s2 = [], []

    def move(self):
        if not self.s2:
            while self.s1:
                self.s2.append(self.s1.pop())

    def push(self, x: int) -> None:
        self.s1.append(x)

    def pop(self) -> int:
        self.move()
        if self.s2:
            return self.s2.pop()
        return -1

    def peek(self) -> int:
        self.move()
        return self.s2[-1]
        
    def empty(self) -> bool:
        return (not self.s1) and (not self.s2)

# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
