class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        if target >= letters[-1]:
            return letters[0]
        lo, hi = 0, len(letters)-1
        while lo < hi:
            mid = lo + (hi-lo) // 2
            if letters[mid] <= target:
                lo = mid+1
            else:
                hi = mid
        return letters[lo]
        
