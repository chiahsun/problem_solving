class Solution:
    def shortestPalindrome(self, s: str) -> str:
        st, left = list(s), []
        while len(st) > 1 :
            if st[0] != st[-1]:
                left.append(st.pop())
            else:
                i, k = 0, len(st)-1
                ok = True
                while i < k:
                    if st[i] != st[k]:
                        ok = False
                        break
                    i += 1; k -= 1
                if ok:
                    break
                else:
                    left.append(st.pop())
        return "".join(left + st + list(reversed(left)))
