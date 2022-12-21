class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:

        def dfs(st, cur, target, res):
            st.append(cur)
            if cur != target:
                for nxt in graph[cur]:
                    dfs(st, nxt, target, res)
            else:
                res.append(st[:])
            st.pop()

        st, res = [], []
        dfs(st, 0, len(graph)-1, res)
        return res
