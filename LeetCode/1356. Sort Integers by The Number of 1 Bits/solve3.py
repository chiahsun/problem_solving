class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        def nbits(a):
            return bin(a).count('1')
        return sorted(arr, key=lambda x: [nbits(x), x])
