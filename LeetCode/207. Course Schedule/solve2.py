class Solution:
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        adjs = collections.defaultdict(list)
        
        for courses in prerequisites:
            adjs[courses[0]].append(courses[1])
        
        visited = [False] * numCourses
        caller = set()
        
        def dfs(x):
            if visited[x]:
                return not x in caller
            visited[x] = True 
            if x in adjs:
                caller.add(x)
                for adj in adjs[x]:
                    if not dfs(adj):
                        return False
                caller.remove(x)
            return True
        
        return all([visited[i] or dfs(i) for i in range(numCourses)])
