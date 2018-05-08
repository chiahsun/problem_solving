import queue

class Solution:
    def openLock(self, deadends, target):
        """
        :type deadends: List[str]
        :type target: str
        :rtype: int
        """
        deadends = set(x for x in deadends)
        
        if '0000' in deadends:
            return -1

        visited = set()
        dist = {}
        
        cur = '0000'
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
                    next[i] = chr(((ord(next[i]) - ord('0') + d) % 10) + ord('0'))
                    next = "".join(next)
                    
                    if not next in visited and not next in deadends:
                        visited.add(next)
                        dist[next] = dist[first]+1
                        q.put(next)
        return -1


