class Solution:
    # @param A : list of integers
    # @return A after the sort
    def sortColors(self, A):
        R = 3
        cnt, B = [0] * (R+1), A[:]
        for a in A:
            cnt[a+1] += 1
        for i in range(2, R):
            cnt[i] += cnt[i-1]
        for b in B:
            A[cnt[b]] = b
            cnt[b] += 1
