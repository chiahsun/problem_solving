class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        N = len(nums)
        def traversal(cur, pos, res):
            if pos == N:
                res.append(cur[:])
                return
            cur.append(nums[pos])
            traversal(cur, pos+1, res)
            cur.pop()
            traversal(cur, pos+1, res)
        st, res = [], []
        traversal(st, 0, res)
        return res
