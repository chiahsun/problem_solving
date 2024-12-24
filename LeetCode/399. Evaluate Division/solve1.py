class Edge:
    def __init__(self, to, weight):
        self.to = to
        self.weight = weight
        
class Solution:
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        adjs = collections.defaultdict(list)
        for i in range(len(equations)):
            pair = equations[i]
            value = values[i]
    
            a, b = pair[0], pair[1]
            adjs[a].append(Edge(b, value))
            adjs[b].append(Edge(a, 1/value))
            
        visited = {}
        def dfs(cur, target):
            if cur == target:
                ret = cur in adjs
                return [ret, 1.0 if ret else -1.0]
            
            visited[cur] = True
            for e in adjs[cur]:
                to = e.to
                weight = e.weight
                if not visited[to]:
                    if to == target:
                        return [True, weight]
                    [ret, val] = dfs(to, target)
                    if ret:
                        return [ret, val * weight]
                        
            return [False, -1.0]
        
        ans = []
        for query in queries:
            visited = {node: False for node in adjs}
            
            [ret, val] = dfs(query[0], query[1])
            ans.append(val)
        return ans
        
