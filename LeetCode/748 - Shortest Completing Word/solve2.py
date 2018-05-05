class Solution:
    @staticmethod
    def add_to_dict(wd):
        d = {}
        for c in wd:
            if c.isalpha():
                c = c.lower()
                if c in d:
                    d[c] += 1
                else:
                    d[c] = 1
        return d
        
    def shortestCompletingWord(self, licensePlate, words):
        """
        :type licensePlate: str
        :type words: List[str]
        :rtype: str
        """
        dl = self.add_to_dict(licensePlate)
        
        min_len = 1001
        ans = ""
        for wd in words:
            if len(wd) < min_len:
                dw = self.add_to_dict(wd)
                ok = True
                for key, value in dl.items():
                    if not key in dw or dw[key] < dl[key]:
                        ok = False
                        break;
                if ok and len(wd) < min_len:
                    min_len = len(wd)
                    ans = wd
        return ans

# s = Solution()
# print(s.shortestCompletingWord("1s3 PSt", ["step","steps","stripe","stepple"]))
# print(s.shortestCompletingWord("1s3 456", ["looks", "pest", "stew", "show"]))

