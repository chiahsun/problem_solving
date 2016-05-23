class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        def is_vowels(c):
            return c in ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
            
        i, k = 0, len(s)-1
        
        s = list(s)
        while i < k:
            while i < len(s) and (not is_vowels(s[i])):
                i += 1
            while k >= 0 and (not is_vowels(s[k])):
                k -= 1
            if i >= k:
                break
            s[i], s[k] = s[k], s[i]
            
            i = i + 1
            k = k - 1
            
        return ''.join(s)
