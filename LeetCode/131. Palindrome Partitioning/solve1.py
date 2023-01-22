class Solution:
    def partition(self, s: str) -> List[List[str]]:

        def is_palindrome(s):
            i, k = 0, len(s)-1
            while i < k:
                if s[i] != s[k]:
                    return False
                i += 1
                k -= 1
            return True
        
        res = []
        def backtracking(s, st):
            if not s:
                res.append(st[:])
                return
            for i in range(1, len(s)+1):
                if is_palindrome(s[:i]):
                    st.append(s[:i])
                    backtracking(s[i:], st)
                    st.pop()
        backtracking(s, [])
        return res

                
