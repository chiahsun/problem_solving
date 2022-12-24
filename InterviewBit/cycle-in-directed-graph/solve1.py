class Solution:
    # @param A : integer
    # @param B : list of list of integers
    # @return an integer
    def solve(self, A, B):
        adj = [[] for _ in range(A)]
        for e in B:
            adj[e[0] - 1].append(e[1] - 1)

        visited, closed = [False] * A, [False] * A

        def has_cycle(pos):
            st = [pos]
            while st:
                top = st.pop()
                if closed[top]:
                    continue
                if all(map(lambda x: closed[x], adj[top])):
                    closed[top] = True
                    continue
                if visited[top]:
                    return True

                visited[top] = True
                st.append(top)
                for t in adj[top]:
                    if not closed[t]:
                        st.append(t)
            return False

        for i in range(A):
            if not closed[i] and has_cycle(i):
                return 1
        return 0


if __name__ == "__main__":
    s = Solution()
    assert s.solve(2, [[1, 2]]) == 0
    assert s.solve(5, [[2, 1], [1, 4], [4, 5], [5, 3], [1, 5], [5, 1]]) == 1
