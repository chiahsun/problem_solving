class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2 == 1:
            return False
        target, M = total // 2, 0
        A = [False] * (target+1)
        A[0] = True
        for n in nums:
            for i in range(min(M+n, target), max(n-1, -1), -1):
                if A[i-n]:
                    A[i] = True
                    M = max(M, i)
        return A[target]
