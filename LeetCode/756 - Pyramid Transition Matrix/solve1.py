class Solution:
    def pyramidTransition(self, bottom, allowed):
        """
        :type bottom: str
        :type allowed: List[str]
        :rtype: bool
        """
        d = collections.defaultdict(list)
        for s in allowed:
            d[s[:2]].append(s[2])
        
        def dfs(bottom, cur, top):
            if len(bottom) == 1:
                return True
            
            if cur == len(bottom)-1:
                return dfs(top, 0, "")
            
            if not bottom[cur:cur+2] in d:
                return False
            
            for c in d[bottom[cur:cur+2]]:
                if dfs(bottom, cur+1, top+c):
                    return True
            return False
        
        return dfs(bottom, 0, "")
