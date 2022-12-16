class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        N, d = len(arr), arr[-1]-arr[0]
        for i in range(1, N):
            d = min(d, arr[i]-arr[i-1])
        res = []
        for i in range(1, N):
            if arr[i]-arr[i-1] == d:
                res.append([arr[i-1], arr[i]])
        return res

