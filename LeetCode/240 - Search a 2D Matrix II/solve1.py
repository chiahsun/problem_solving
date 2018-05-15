class Solution(object):
    def search(self, matrix, row_lo, row_hi, col_lo, col_hi, target):
        if row_lo > row_hi or col_lo > col_hi:
            return False
        row_mid = (row_lo+row_hi)//2
        col_mid = (col_lo+col_hi)//2
        mid = matrix[row_mid][col_mid]
        
        if row_lo == row_hi:
            while col_lo <= col_hi:
                m = col_lo + (col_hi-col_lo)//2
                if matrix[row_lo][m] == target:
                    return True
                elif matrix[row_lo][m] > target:
                    col_hi = m-1
                else:
                    col_lo = m+1
            return False
        if col_lo == col_hi:
            while row_lo <= row_hi:
                m = row_lo + (row_hi - row_lo)//2
                if matrix[m][col_lo] == target:
                    return True
                elif matrix[m][col_lo] > target:
                    row_hi = m-1
                else:
                    row_lo = m+1
            return False     
        
        if mid == target:
            return True
        if self.search(matrix, row_mid+1, row_hi, col_lo, col_mid-1, target) or self.search(matrix, row_lo, row_hi-1, col_mid+1, col_hi, target):
            return True
        if target < mid:
            return self.search(matrix, row_lo, row_mid, col_lo, col_mid, target)
        return self.search(matrix, row_mid+1, row_hi, col_mid, col_hi, target) or self.search(matrix, row_mid, row_hi, col_mid+1, col_hi, target)
        
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        
        return self.search(matrix, 0, len(matrix)-1, 0, len(matrix[0])-1, target)


s = Solution()
#print(s.searchMatrix([[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], 5))
#print(s.searchMatrix([[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], 20))
