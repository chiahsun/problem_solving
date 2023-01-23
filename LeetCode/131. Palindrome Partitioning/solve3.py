class Solution:
    def partition(self, s: str) -> List[List[str]]:
        N = len(s)
        dp = [[False] * N for _ in range(N)]
        res = []
        def backtracking(s, pos, st):
            if pos == N:
                res.append(st[:])
                return
            for end in range(pos, N):
                if pos + 1 >= end or dp[pos+1][end-1]:
                    if s[pos] == s[end]:
                        dp[pos][end] = True
                        st.append(s[pos:end+1])
                        backtracking(s, end+1, st)
                        st.pop()
        backtracking(s, 0, [])
        return res
