import queue

class Solution:
    def openLock(self, deadends, target):
        """
        :type deadends: List[str]
        :type target: str
        :rtype: int
        """
        def next_number(cur):
            for i in range(4):
                for d in (-1, 1):
                    c = str((int(cur[i]) + d + 10) % 10)
                    yield "".join([cur[:i], c, cur[i+1:]])
        
        deadends = set(deadends)
        
        if '0000' in deadends:
            return -1

        cur = '0000'
        visited = set(cur)
        q = [cur]
        distance = 0
        
        while q:
            next_q = []
            
            for x in q:
                if x == target:
                    return distance
            
                for next in next_number(x):
                    if not next in visited and not next in deadends:
                        if next == target:
                            return distance + 1
                        visited.add(next)
                        next_q.append(next)
            q = next_q
            distance += 1
        return -1


