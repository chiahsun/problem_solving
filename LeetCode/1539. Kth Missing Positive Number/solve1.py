class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        d = { arr[i]: i for i in range(len(arr)) }

        def f(x):
            # print(x, ': ', f(x), ' ', len(arr), ' ', arr)
            return 0 if x - d[x] - 1 < k else 1

        pos = bisect.bisect_right(arr, 0, key=f)
        # print(pos, k)
        return pos + k

