# [4,5,0,-2,-3,1]
# 4  {4:1    }
# 5  {4:1 0:1}   +1
# 0  {4:1 0:2}   +2
# -2 {2:1 3:3 } 
# -3 {4:1 0:3 2:1}  +3
# 1  {0:1 1:2 3:1 1:1} + 1
class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        d, offset, res = defaultdict(int), 0, 0
        for n in nums:
            offset = (offset + n) % k
            d[(n - offset) % k] += 1
            res += d[(-offset) % k]
            
        return res

