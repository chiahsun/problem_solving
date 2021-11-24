class Solution(object):

    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix or not matrix[0]:
            return False
        i, k = 0, len(matrix[0])-1
        
        while k >= 0 and i < len(matrix):
            if matrix[i][k] == target:
                return True
            elif matrix[i][k] < target:
                i += 1
            else:
                k -= 1
        return False
