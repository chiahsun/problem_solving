class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        s = set(arr)
        n_zeros = 0
        for a in reversed(arr):
            if a == 0:
                n_zeros += 1
            if a % 2 == 0 and (a // 2) in s and a != 0:
                return True
        return n_zeros > 1
