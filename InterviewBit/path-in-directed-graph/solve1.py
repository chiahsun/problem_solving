import random


class Solution:
    # @param A : integer
    # @param B : list of list of integers
    # @return an integer
    def solve(self, A, B):
        adj = [[] for _ in range(A)]
        for e in B:
            adj[e[0] - 1].append(e[1] - 1)
        visited = [False] * A

        st = [0]
        while st:
            cur = st.pop()
            if cur == A-1:
                return 1
            visited[cur] = True
            for t in adj[cur]:
                if not visited[t]:
                    st.append(t)
        return 0

if __name__ == "__main__":
    s = Solution()
    assert s.solve(5, [[1, 2], [4, 1], [2, 4], [3, 4], [5, 2], [1, 3]]) == 0
    assert s.solve(5, [[1, 2], [2, 3], [3, 4], [4, 5]]) == 1

    e = []
    N = 5000
    random.seed(1)
    for i in range(N*2):
        e.append([1 + random.randint(0, N - 1), 1 + random.randint(0, N - 1)])
    print(s.solve(N, e))
