class Solution:
    def specialArray(self, nums: List[int]) -> int:
        # 3 5 -> 2

        # 0 0 3 4 4 -> 3

        # 3 3 3 3 -> -1
        N = len(nums)
        nums.sort()
        def get_nok(candidate):
            return N - bisect.bisect_left(nums, candidate)

        def search(lo, hi):
            if lo == hi:
                return lo if lo == get_nok(lo) else -1
            mid = lo + (hi-lo) // 2
            nok = get_nok(mid)
            if nok == mid:
                return mid
            elif nok > mid or mid == lo:
                return search(mid+1, hi)
            else:
                return  search(lo, mid-1)
        return search(0, len(nums))
