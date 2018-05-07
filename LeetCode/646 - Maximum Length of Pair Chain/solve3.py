class Solution:
    def findLongestChain(self, pairs):
        """
        :type pairs: List[List[int]]
        :rtype: int
        """

        last_end = -0x7FFFFFFF
        pairs.sort(key = lambda x: x[1])

        count = 0
        for pair in pairs:
            if pair[0] > last_end:
                last_end = pair[1]
                count += 1
        return count
