class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        res = []

        def backtracking(s, left, st):
            if left == 0:
                res.append(".".join(st))
                return
            for i in range(1, 4):
                if 0 <= int(s[:i]) <= 255 and (int(s[0]) != 0 or i == 1) and (left-1) * 1 <= len(s) - i <= (left-1) * 3:
                    st.append(s[:i])
                    backtracking(s[i:], left-1, st)
                    st.pop()

        backtracking(s, 4, [])
        return res
