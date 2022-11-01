class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        def binary_search_min_d(a, target):
            lo, hi = 0, len(a)-1
            if target <= a[lo]:
                return a[lo] - target
            if a[hi] <= target:
                return target - a[hi]
            while lo < hi:
                mid = lo + (hi-lo) // 2
                if  target >= a[mid]:
                    lo = mid+1
                else:
                    hi = mid
            return min(target - a[lo-1], a[lo]-target)

        ans = 0
        arr2.sort()
        for a in arr1:
            if binary_search_min_d(arr2, a) > d:
                ans += 1
        return ans 

