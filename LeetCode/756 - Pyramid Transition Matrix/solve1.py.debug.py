import collections
class Solution:
    def pyramidTransition(self, bottom, allowed):
        """
        :type bottom: str
        :type allowed: List[str]
        :rtype: bool
        """
        d = collections.defaultdict(list)
        for s in allowed: # TODO: check duplicate
            d[s[:2]].append(s[2])
        
        def dfs(bottom, cur, top):
            if len(bottom) == 1:
                return True
            
            if cur == len(bottom)-1:
                print('Use bottom: ', bottom)
                return dfs(top, 0, "")
            
            if not bottom[cur:cur+2] in d:
                return False
            
            #print('d: ', d)
            for c in d[bottom[cur:cur+2]]:
                if dfs(bottom, cur+1, top+c):
                    return True
            return False
        
        return dfs(bottom, 0, "")

s = Solution()
#print(s.pyramidTransition("XYZ", ["XYD", "YZE", "DEA", "FFF"]))
print(s.pyramidTransition("XXYX", ["XXX", "XXY", "XYX", "XYY", "YXZ"]))
