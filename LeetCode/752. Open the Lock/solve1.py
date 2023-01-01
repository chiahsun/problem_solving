import queue

class Solution:
    def openLock(self, deadends, target):
        """
        :type deadends: List[str]
        :type target: str
        :rtype: int
        """
        deadends = set([tuple(map(int, tuple(x))) for x in deadends]) 
        target = tuple(map(int, tuple(target)))
        
        if (0, 0, 0, 0) in deadends:
            return -1
        
        cur = (0, 0, 0, 0)
        visited = set()
        dist = {}
        
        q = queue.Queue()
        visited.add(cur)
        dist[cur] = 0
        q.put(cur)
        
        while not q.empty():
            first = q.get()
            if first == target:
                return dist[first]
            
            for i in range(4):
                for d in (-1, 1):
                    next = list(first)
                    next[i] = (next[i] + d) % 10
                    next = tuple(next)
                    
                    if not next in visited and not next in deadends:
                        visited.add(next)
                        dist[next] = dist[first]+1
                        q.put(next)
        return -1


