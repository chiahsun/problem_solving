class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        d = { arr[i]: i for i in range(len(arr)) }
        return bisect.bisect_right(arr, 0, key=lambda x: 0 if x - d[x] - 1 < k else 1) + k

