class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        N = len(arr)
        arr.sort()
        for a in arr:
            target = 2 * a
            pos = bisect.bisect_left(arr, target)
            if pos >= 0 and pos < N and target == arr[pos]:
                if target != 0 or (pos+1 < N and arr[pos+1] == 0):
                    return True
        return False
