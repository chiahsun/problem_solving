# User function Template for python3
class Solution:
    def findMaxFlow(self, N, M, Edges):
        adj = [[] for _ in range(N)]
        for i, e in enumerate(Edges):
            f, t = e[0] - 1, e[1] - 1
            e[0], e[1] = f, t
            adj[f].append(i)
            adj[t].append(i)

        F = [0] * M

        def find_augment_path():

            def path_to_source_target_path(path):
                cur, st = N - 1, []
                while cur != 0:
                    eid = path[cur]
                    f, t = Edges[eid][0], Edges[eid][1]
                    st.append(eid)
                    cur = t if f == cur else f
                return list(reversed(st))

            visited, path, q = [False] * N, [-1] * N, [0]
            visited[0] = True
            while q:
                qn = []
                for v in q:
                    for eid in adj[v]:
                        e = Edges[eid]
                        f, t, cap, flow = e[0], e[1], e[2], F[eid]
                        if v == f and cap - flow > 0 and not visited[t]:
                            path[t] = eid
                            if t == N - 1:
                                return path_to_source_target_path(path)
                            visited[t] = True
                            qn.append(t)
                        elif v == t and flow + cap > 0 and not visited[f]:
                            path[f] = eid
                            if f == N - 1:
                                return path_to_source_target_path(path)
                            visited[f] = True
                            qn.append(f)
                q = qn
            return []

        def fill_augment_path(path):
            augment_flow, cur = 1000 * 2, 0
            for eid in path:
                e = Edges[eid]
                f, t, cap, flow = e[0], e[1], e[2], F[eid]
                if f == cur:
                    augment_flow = min(augment_flow, cap - flow)
                    cur = t
                else:
                    augment_flow = min(augment_flow, flow + cap)
                    cur = f
            cur = 0
            for eid in path:
                e = Edges[eid]
                f, t, cap = e[0], e[1], e[2]
                if f == cur:
                    F[eid] += augment_flow
                    cur = t
                else:
                    F[eid] -= augment_flow
                    cur = f
            return augment_flow


        res = 0
        while True:
            path = find_augment_path()
            if not path:
                break
            res += fill_augment_path(path)

        return res


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N, M = map(int, input().strip().split())
        Edges = []
        input_line = list(map(int, input().strip().split()))
        for i in range(M):
            Edges.append([input_line[3 * i], input_line[3 * i + 1], input_line[3 * i + 2]])

        ob = Solution()
        ans = ob.findMaxFlow(N, M, Edges)
        print(ans)

# } Driver Code Ends
