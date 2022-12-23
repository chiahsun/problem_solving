class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        N, res = len(nums), []

        def traversal(pos):
            if pos == N:
                res.append(nums[:])
                return
            s = set()
            for i in range(pos, N):
                if nums[i] not in s:
                    s.add(nums[i])
                    nums[pos], nums[i] = nums[i], nums[pos]
                    traversal(pos+1)
                    nums[pos], nums[i] = nums[i], nums[pos]

        traversal(0)
        return res
