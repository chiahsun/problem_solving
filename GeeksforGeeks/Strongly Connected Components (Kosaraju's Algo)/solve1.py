#User function Template for python3

class Solution:
    
    #Function to find number of strongly connected components in the graph.
    def kosaraju(self, V, adj):
        E = adj
        RE = [[] for _ in range(V)]
        for i in range(V):
            for t in E[i]:
                RE[t].append(i)
        
        def topogical_sort():
            st, visited, closed = [], set(), set()
            
            def dfs(pos):
                visited.add(pos)
                for nxt in RE[pos]:
                    if nxt not in visited:
                        dfs(nxt)
                st.append(pos)
                closed.add(pos)
                
            for i in range(V):
                if i not in closed:
                    dfs(i)
            return st
        
        res, visited = 0, [False] * V
        def dfs2(x):
            visited[x] = True
            for nxt in E[x]:
                if not visited[nxt]:
                    dfs2(nxt)
            
        for a in reversed(topogical_sort()):
            if not visited[a]:
                res += 1
                dfs2(a)
        return res
            
            


#{ 
 # Driver Code Starts
#Initial Template for Python 3

from collections import OrderedDict 
import sys 

sys.setrecursionlimit(10**6) 
if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        V,E = list(map(int, input().strip().split()))
        adj = [[] for i in range(V)]
        for i in range(E):
            a,b = map(int,input().strip().split())
            adj[a].append(b)
        ob = Solution()
        
        print(ob.kosaraju(V, adj))
# } Driver Code Ends
