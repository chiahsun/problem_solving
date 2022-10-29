class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        def str_to_dict(s):
            d = {}
            for c in s:
                d[c] = d.get(c, 0) + 1
            return d
        return str_to_dict(s) == str_to_dict(t)
