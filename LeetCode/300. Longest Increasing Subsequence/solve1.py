class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        L = []
        for n in nums:
            if not L or L[-1] < n:
                L.append(n)
            else:
                L[bisect_left(L, n)] = n
        return len(L)
