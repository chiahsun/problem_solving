class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        def encode(row, N, margin=False):
            res = 0
            for d in row:
                res = (res << 1) + d
            if margin:
                res = res << (N-1)
            return res
        
        def num_of_ones(x):
            cnt = 0
            while x > 0:
                cnt += 1
                x &= (x-1)
            return cnt

        N = len(img1)
        A = [0] * (N-1)
        for row in reversed(img1):
            A.append(encode(row, N, margin=True))
        A.extend([0] * (N-1))
        # print(A)
 
        B = [encode(row, N) for row in reversed(img2)]
        # print(B)
        ans = 0
        for i in range(0, len(A)-N+1):
            for k in range(2*N-1):
                cur = 0            
                for n in range(N):
                    cur += (num_of_ones((A[i+n] >> k) & B[n]))
                    # print("now: ", A[i+n] >> k, ' and ', B[n])
                ans = max(ans, cur)
                # print("cur: ", cur)
        return ans
