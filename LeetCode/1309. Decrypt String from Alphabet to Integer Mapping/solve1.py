class Solution:
    def freqAlphabets(self, s: str) -> str:
        i, N = 0, len(s)
        ans = []
        while i < N:
            if i+2 < N and s[i+2] == '#':
                ans.append(chr(int(s[i:i+2]) - 10 + ord('j')))
                i += 3
            else:
                ans.append(chr(int(s[i:i+1]) - 1 + ord('a')))
                i += 1
        return "".join(ans)
