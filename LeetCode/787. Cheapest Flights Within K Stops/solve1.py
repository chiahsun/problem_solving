import queue

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        adjs = [[] for _ in range(n)]
        max_hop = k+1
        for flight_id, flight in enumerate(flights):
            f = flight[0]
            adjs[f].append(flight_id)
        INF = sys.maxsize
        pq = queue.PriorityQueue()
        d = [INF] * n
        pq.put((0, 0, src))
        while not pq.empty():
            hop, cost, city = pq.get()
            if d[city] <= cost:
                continue
            d[city] = cost
            if hop >= max_hop:
                continue
            next_hop = hop + 1
            for flight_id in adjs[city]:
                flight = flights[flight_id]
                t, price = flight[1], flight[2]
                next_cost = cost + price
                if d[t] <= next_cost:
                    continue
                pq.put((next_hop, next_cost, t))
        return d[dst] if d[dst] != INF else -1

        
