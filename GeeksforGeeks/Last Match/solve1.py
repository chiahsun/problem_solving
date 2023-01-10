# User function Template for python3
class Solution:
    # ABABAC
    # --012-
    def findLastOccurence(self, A, B):
        N = len(B)
        fallback = [-1] * N
        for i in range(1, N):
            c, prev = B[i], fallback[i - 1]
            while prev >= 0 and c != B[prev + 1]:
                prev = fallback[prev]
            if B[prev + 1] == c:
                fallback[i] = prev + 1
        # print('fallback: ', fallback)
        res, pos = -1, -1
        for i, c in enumerate(A):
            if pos == N - 1:
                pos = fallback[pos]
                while pos >= 0 and B[pos + 1] != c:
                    pos = fallback[pos]
            else:
                while pos >= 0 and B[pos + 1] != c:
                    pos = fallback[pos]
            if B[pos + 1] == c:
                pos += 1
            if pos == N - 1:
                res = i - N + 2  # 1-based index

        return res


# {
# Driver Code Starts
# Initial Template for Python 3
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        A = input()
        B = input()

        ob = Solution()
        print(ob.findLastOccurence(A, B))
# } Driver Code Ends