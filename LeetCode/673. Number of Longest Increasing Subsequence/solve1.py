# [3,2,1,6,5,4,3]
# 3       2          1          6
# [3:1]   [3:1       [3:1       [3:1  [6:3]
#          2:1+1=2]   2:2        2:2
#                     1:2+1=3]   1:3]
#
# 5                 4
# [3:1  [6:3        [3:1  [6:3
#  2:2   5:3+3=6]    2:2   5:6
#  1:3]              1:3]  4:6+3=9]
#
# 3
# [3:1  [6:3
#  2:2   5:6
#  1:3]  4:9
#        3:9+2=11]

# [1,4,6,3,4]
# [1:1] [4:1]       [6:1]
#       [3:1+1=2]   [4:1+(2-1)=2]

class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        first, N = nums[0], len(nums)
        A, B, P = [[first]], [first], [[1]]

        def find_paths(A, B, pos, n):
            if n > A[pos][0]:
                return P[pos][-1]
            if n == A[pos][-1]:
                return 1
            my_key = lambda x: -x
            i = bisect_right(A[pos], my_key(n), key=my_key)
            return P[pos][-1] - P[pos][i-1]

        for i in range(1, N):
            n = nums[i]
            pos = bisect_left(B, n)
            if pos < len(A):
                P[pos].append(P[pos][-1] + (1 if pos == 0 else find_paths(A, B, pos-1, n)))
                A[pos].append(n)
                B[pos] = n
            else:
                P.append([find_paths(A, B, -1, n)])
                A.append([n])
                B.append(n)
        return P[-1][-1]

