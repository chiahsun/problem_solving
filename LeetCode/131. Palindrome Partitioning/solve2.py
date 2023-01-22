class Solution:
    def partition(self, s: str) -> List[List[str]]:
        N = len(s)
        dp = [[1] for _ in range(N)]
        for i in range(N):
            k = i
            while i-1 >= 0 and k+1 < N and s[i-1] == s[k+1]:
                i -= 1
                k += 1
                dp[i].append(k-i+1)
        for i in range(N):
            k = i+1
            while i >= 0 and k < N and s[i] == s[k]:
                dp[i].append(k-i+1)
                i -= 1
                k += 1
        
        res = []
        def backtracking(s, pos, st):
            if pos == N:
                res.append(st[:])
                return
            for i in dp[pos]:
                st.append(s[pos:pos+i])
                backtracking(s, pos+i, st)
                st.pop()
        backtracking(s, 0, [])
        # print(dp)
        return res

                
