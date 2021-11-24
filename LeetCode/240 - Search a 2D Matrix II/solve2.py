class Solution(object):

    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        for row in matrix:
            if not row:
                return False
            lo, hi = 0, len(row)-1
            while lo <= hi:
                m = lo + (hi-lo)//2
                val = row[m]
                if target > val:
                    lo = m+1
                elif target < val:
                    hi = m-1
                else:
                    return True
        return False
