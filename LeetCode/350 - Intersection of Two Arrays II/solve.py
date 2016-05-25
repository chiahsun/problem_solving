class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        nums1.sort()
        nums2.sort()
        i, k = 0, 0
        
        res = []
        while i < len(nums1) and k < len(nums2):
            a, b = nums1[i], nums2[k]
            if a == b:
                res.append(a)
                i += 1
                k += 1
            elif a < b:
                i += 1
            else:
                k += 1
        return res
                
