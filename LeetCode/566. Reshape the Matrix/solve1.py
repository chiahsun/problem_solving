class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        if r * c != len(mat) * len(mat[0]):
            return mat
        ans, cur = [], []
        for row in mat:
            for elem in row:
                cur.append(elem)
                if len(cur) == c:
                    ans.append(cur)
                    cur = []
        return ans
        
