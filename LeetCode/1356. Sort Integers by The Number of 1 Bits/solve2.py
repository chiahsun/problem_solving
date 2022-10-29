class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        def nbits(a):
            cnt = 0
            while a > 0:
                cnt += 1
                a &= (a - 1)
            return cnt
        return sorted(arr, key=lambda x: [nbits(x), x])
