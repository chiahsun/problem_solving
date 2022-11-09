class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        # 100 20 10 10 5     cur: 10
        #   0  0  1  1 2
         # 100 20 10 10 5     cur: 11
        #   0  0   2  2 2 
        ans = 0
        for i in range(len(nums1)):
            if len(nums2) - i - 1 <= ans:
                break
            cur = nums1[i]

            def my_key(x):
                if x == cur:
                    return 1
                elif x < cur:
                    return 2
                return 0
            # print(nums2, ' cur: ', cur)
            # print(list(map(my_key, nums2)))
            pos = bisect_right(nums2, 1, key=my_key, lo=i)-1
            if pos < len(nums2):
                # print('cur: ', cur, ' pos: ', pos, ' val: ', nums2[pos])
                ans = max(ans, pos-i)
        return ans


