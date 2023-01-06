class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        # https://docs.python.org/3/library/heapq.html
        max_heap, res = [], 0
        for cost in costs:
            if coins >= cost:
                heappush(max_heap, (-cost, cost))
                coins -= cost
                res += 1
            else:
                if max_heap and max_heap[0][1] > cost:
                    max_item = heappop(max_heap)
                    coins = coins + max_item[1] - cost 
                    heappush(max_heap, (-cost, cost))
        return res
