class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        ans = 0
        N = len(arr)
        psum = [0] * N
        psum[0] = arr[0]
        for i in range(1, N):
            psum[i] = psum[i-1] + arr[i]
        print(psum)
        for i in range(1, N+1, 2):
            for k in range(0, N):
                if k+i > N:
                    break
                cur = psum[k+i-1] - (psum[k-1] if k >= 1 else 0)
                # print('start: ', k, 'end: ', k+i, 'sub array: ', arr[k: k+i], 'cur: ', cur, ' ', psum[k+i-1], ' - ', psum[k-1] if k >= 1 else 0)

                ans += cur
        return ans
