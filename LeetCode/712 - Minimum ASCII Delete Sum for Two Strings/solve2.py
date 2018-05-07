class Solution:
    def minimumDeleteSum(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: int
        """
        val = [[0 for _ in range(len(s2))] for _ in range(len(s1))]
        if s1[0] == s2[0]:
            val[0][0] = ord(s1[0])
        
        for i in range(1, len(s1)):
            val[i][0] = max(ord(s2[0]) if s1[i] == s2[0] else 0, val[i-1][0])

        for i in range(1, len(s2)):
            val[0][i] = max(ord(s1[0]) if s1[0] == s2[i] else 0, val[0][i-1])

        for i in range(1, len(s1)):
            for k in range(1, len(s2)):
                if s1[i] == s2[k]:
                    val[i][k] = val[i-1][k-1] + ord(s1[i])
                else:
                    val[i][k] = max(val[i-1][k], val[i][k-1])
                    
        return sum(map(ord, s1)) + sum(map(ord, s2)) - 2*val[len(s1)-1][len(s2)-1]

