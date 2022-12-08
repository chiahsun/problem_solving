class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        N, res = len(nums), nums[0]
        P, N = 0, 0
        for i, n in enumerate(nums):
            if n == 0:
                P = 0; N = 0; res = max(P, res)
            elif n >= 0:
                P, N = P * n if P != 0 else n, N * n
                res = max(P, res)
            else:
                P, N = N * n, P * n if P > 0 else n
                if P > 0:
                    res = max(P, res)
            # print('i: ', i, ' ', n, 'P: ', P, 'N: ', N)
        return res
            
