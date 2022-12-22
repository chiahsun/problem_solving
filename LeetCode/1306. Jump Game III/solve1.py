class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        if arr[start] == 0:
            return True
        d = arr[start]
        arr[start] = -1
        for n in [start+d, start-d]:
            if n >= 0 and n < len(arr) and arr[n] >= 0:
                if self.canReach(arr, n):
                    return True
        return False
