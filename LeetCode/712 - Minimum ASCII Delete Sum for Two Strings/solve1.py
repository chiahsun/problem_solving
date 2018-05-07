class Solution:
    def minimumDeleteSum(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: int
        """
        dp = [[0 for _ in range(len(s2))] for _ in range(len(s1))]
        val = [[0 for _ in range(len(s2))] for _ in range(len(s1))]
        if s1[0] == s2[0]:
            dp[0][0] = 1
            val[0][0] = ord(s1[0])
        
        for i in range(1, len(s1)):
            cur_dp, cur_val = 0, 0
            if s1[i] == s2[0]:
                cur_dp = 1
                cur_val = ord(s2[0])
            dp[i][0] = max(cur_dp, dp[i-1][0])
            val[i][0] = max(cur_val, val[i-1][0])

        for i in range(1, len(s2)):
            cur_dp, cur_val = 0, 0
            if s1[0] == s2[i]:
                cur_dp = 1
                cur_val = ord(s1[0])
            dp[0][i] = max(cur_dp, dp[0][i-1])
            val[0][i] = max(cur_val, val[0][i-1])

        for i in range(1, len(s1)):
            for k in range(1, len(s2)):
                if s1[i] == s2[k]:
                    dp[i][k] = dp[i-1][k-1] + 1
                    val[i][k] = val[i-1][k-1] + ord(s1[i])
                else:
                    dp[i][k] = max(dp[i-1][k], dp[i][k-1])
                    val[i][k] = max(val[i-1][k], val[i][k-1])
        # print(dp)
        # print(val)
        return sum(map(ord, s1)) + sum(map(ord, s2)) - 2*val[len(s1)-1][len(s2)-1]

#s = Solution()
#print(s.minimumDeleteSum("sea", "eat"))
#print(s.minimumDeleteSum("delete", "leet"))

