
class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        mp, word_set = {}, set()

        pattern = list(pattern)
        strs = str.split(" ")

        if len(strs) != len(pattern):
            return False

        for i in range(len(pattern)):
            p, s = pattern[i], strs[i]
            if p in mp:
                if mp[p] != s:
                    return False
            else:
                if s in word_set:
                    return False;
                mp[p] = s
                word_set.add(s)

        return True



s = Solution()
print(s.wordPattern("abba", "dog cat cat dog"));
print(s.wordPattern("abba", "dog dog dog dog"));
print(s.wordPattern("jquery", "jquery"));
