class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        d = {}
        candidates = []
        for cur in reversed(nums2):
            while len(candidates) > 0 and candidates[-1] <= cur:
                candidates.pop()
            if len(candidates) > 0:
                d[cur] = candidates[-1]
            
            candidates.append(cur)
        return [-1 if a not in d else d[a] for a in nums1]
