import collections

class Solution:
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        adjs = collections.defaultdict(list)
        for prereq in prerequisites:
            adjs[prereq[1]].append(prereq[0])
            
        visited = [False] * numCourses
        done = set()
        reverseOrder = []
        
        def dfs(cur):
            if visited[cur]:
                return cur in done
            
            visited[cur] = True
            if cur in adjs:
                for next in adjs[cur]:
                    if not dfs(next):
                        return False
            reverseOrder.append(cur)
            done.add(cur)
                
            return True
        
        return list(reversed(reverseOrder)) if all([dfs(i) for i in range(numCourses)]) else []
