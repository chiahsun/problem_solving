class Solution(object):
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        for row in A:
            for i in range(len(row)//2):
                row[i], row[len(row)-i-1] = row[len(row)-i-1], row[i]
            for i in range(len(row)):
                row[i] = 1 if row[i] == 0 else 0
        return A
