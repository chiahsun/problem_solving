import queue
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        q = queue.PriorityQueue()
        for stone in stones:
            q.put((-stone, stone))
        while not q.empty():
            _, a = q.get()
            if q.empty():
                return a
            _, b = q.get()
            c = a - b
            q.put((-c, c))

        return 0
