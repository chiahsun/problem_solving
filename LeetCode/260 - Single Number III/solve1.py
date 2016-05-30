class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        k = list(range(0, len(nums)))
        a = sorted(nums)
        k.sort(key=lambda x: nums[x]) 
        
        
        idx = []
        i = 0
        while i < len(nums):
            if i+1 < len(nums) and a[i] == a[i+1]:
                i += 2
            else:
                idx.append(k[i])
                i += 1
                
        res = list(map(lambda i: nums[i], idx))
        while len(res) < 2:
            res.append(0)
            
        return res
                

s = Solution()
print(s.singleNumber([0, -1]));
print(s.singleNumber([1, 2, 1]));
print(s.singleNumber([1, 2, 1, 3, 2, 5]));

