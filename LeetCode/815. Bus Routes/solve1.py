import queue

class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        bus_routes = defaultdict(list)
        for route_id, rt in enumerate(routes):
            for bus in rt:
                bus_routes[bus].append(route_id)
        q, d, inq = [source], 0, set([source])
        while q:
            qn = []
            for id in q:
                if id == target:
                    return d
                for route_id in bus_routes[id]:
                    for other_bus in routes[route_id]:
                        if not other_bus in inq:
                            inq.add(other_bus)
                            qn.append(other_bus)
                    routes[route_id] = [] # This line is critical for passing TLE
            d += 1
            q = qn
        return -1 
