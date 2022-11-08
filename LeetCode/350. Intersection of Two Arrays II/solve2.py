class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        d1 = {}
        for n in nums1:
            d1[n] = d1.get(n, 0) + 1
        ans = []
        for n in nums2:
            if d1.get(n, 0) > 0:
                ans.append(n)
                d1[n] -= 1
        return ans

