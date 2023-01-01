class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        in_degree = [0] * n
        for e in edges:
            in_degree[e[1]] += 1
        return filter(lambda x: in_degree[x] == 0 , list(range(n)))
