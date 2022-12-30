class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        A = [defaultdict(int)]

        for n in nums:
            for i in range(len(A)):
                if i == 0:
                    A[i][n] += 1
                if n == min(A[i].keys()):
                    break
                cnt = 0
                for k in A[i].keys():
                    if k < n:
                        cnt += A[i][k]
                if i+1 == len(A):
                    A.append(defaultdict(int))
                A[i+1][n] += cnt
        return sum(A[-1].values())
