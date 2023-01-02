class Solution:
    def isBipartite(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: bool
        """
        color = [None] * len(graph)
        
        def dfs(x, col):
            if color[x] is not None:
                return col == color[x]
            color[x] = col
            for y in graph[x]:
                if not dfs(y, not col):
                    return False
            return True
        
        for i in range(len(graph)):
            if color[i] is None:
                if not dfs(i, True):
                    return False
                
        return True
