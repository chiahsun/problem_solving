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
        
        cur = '0000'
        q = [cur]
        distance = 0
        
        while q:
            next_q = []
            
            for x in q:
                if x == target:
                    return distance
            
                for i in range(4):
                    for d in (-1, 1):
                        next = list(x)
                        next[i] = str((int(next[i]) + d + 10) % 10)
                        next = "".join(next)
                    
                        if not next in visited and not next in deadends:
                            visited.add(next)
                            next_q.append(next)
            q = next_q
            distance += 1
        return -1


