class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        start, product, res, N = 0, 1, 0, len(nums)
        for i in range(N):
            cur = nums[i]
            while start < i and product * cur >= k:
                if product < k:
                    res += i - start
                product = product // nums[start]
                start += 1
            product = product * cur
        return res + ((N-start+1)*(N-start)//2 if product < k else 0)
