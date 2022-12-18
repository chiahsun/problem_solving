class Solution:
    def smallestTrimmedNumbers(self, nums: List[str], queries: List[List[int]]) -> List[int]:
        N, res = len(nums), []
        for q in queries:
            A, l = list(range(N)), q[1]
            A.sort(key=lambda i: nums[i][-l:])
            res.append(A[q[0]-1])
        return res
