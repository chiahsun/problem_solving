class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def get_str(s):
            st = []
            for c in s:
                if c != '#':
                    st.append(c)
                elif st:
                    st.pop()
            return "".join(st)
        return get_str(s) == get_str(t)
        
