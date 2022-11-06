class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        i, k = len(matrix[0])-1, 0
        while k < len(matrix):
            if matrix[k][i] == target:
                return True
            elif matrix[k][i] > target:
                while i >= 0:
                    if matrix[k][i] == target:
                        return True
                    i -= 1
                return False
            k += 1
        return False
        
