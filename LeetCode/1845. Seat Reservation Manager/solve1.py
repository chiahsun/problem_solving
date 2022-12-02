import queue
class SeatManager:

    def __init__(self, n: int):
        q = queue.PriorityQueue()
        for i in range(1, n+1):
            q.put((i, i))
        self.q = q
        
    def reserve(self) -> int:
        return self.q.get()[1]
        
    def unreserve(self, seatNumber: int) -> None:
        self.q.put((seatNumber, seatNumber))

# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)
