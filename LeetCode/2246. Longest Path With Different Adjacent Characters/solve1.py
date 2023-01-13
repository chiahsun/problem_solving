class Solution:
    def longestPath(self, parent: List[int], s: str) -> int:
        res, N = 1, len(s)
        children = [[] for _ in range(N)]
        for i in range(1, N):
            p = parent[i]
            children[p].append(i)

        def traversal(pos):
            nonlocal res
            if not children[pos]:
                return 1
            depths = []
            for ch in children[pos]:
                if s[ch] != s[pos]:
                    depths.append(traversal(ch))
                    depths.sort()
                    depths = depths[-2:]
                else:
                    traversal(ch)
            if not depths:
                return 1
            res = max(res, sum(depths) + 1)
            return 1 + depths[-1]

        traversal(0)
        return res
