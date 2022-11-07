class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        N = len(mat[0])
        def my_cmp(x, y): 
            for i in range(N):
                if mat[x][i] != mat[y][i]:
                    return -1 if mat[x][i] < mat[y][i] else 1
            return -1 if x < y else 1
        return sorted(list(range(len(mat))), key=cmp_to_key(my_cmp))[:k]
