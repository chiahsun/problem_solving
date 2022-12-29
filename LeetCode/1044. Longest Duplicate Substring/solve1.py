class Solution:
    def longestDupSubstring(self, s: str) -> str:
        N, res = len(s), ""
        L = list(range(N))

        # TODO: Concat A as order list or inplace recursive subset 3-way quick sort
        # L.sort(key=lambda i: s[i:]) # timeout for this, but result should be the same
        def suffix_sort(L):

            def get_first_order_array(L):
                B, pos = [0] * N, 0
                for i in range(N):
                    if i > 0 and s[L[i]] != s[L[i - 1]]:
                        pos += 1
                    B[L[i]] = pos
                return B

            def get_order_array(L, A, cnt):
                B, pos = [0] * N, 0
                for i in range(N):
                    if i == 0 or L[i - 1] + cnt >= N:
                        pass
                    elif L[i] + cnt >= N or A[L[i] + cnt] != A[L[i - 1] + cnt]:
                        pos += 1
                    B[L[i]] = pos
                return B

            L.sort(key=lambda i: s[i])
            B = get_first_order_array(L)
            A = [[B[i]] for i in range(N)]
            cnt = 1

            while cnt < N:
                L.sort(key=lambda i: A[i + cnt] if (i + cnt < N) else [-1])
                B = get_order_array(L, A, cnt)

                for i in range(N):
                    A[i].append(B[i])
                cnt *= 2
            L.sort(key=lambda i: A[i])
            return A

        A = suffix_sort(L)
        # L = sorted(L, key=lambda i: s[i:])

        def lcp(a, b, L, A):
            if a >= N or b >= N:
                return 0
            if s[a] != s[b]:
                return 0
            res, cnt = 1, 1
            for i in range(1, len(A)):
                if A[a][i] == A[b][i]:
                    res += cnt
                    cnt *= 2
                    if res > N-a or res > N-b:
                        res = min(N-a, N-b)
                        break
                else:
                    res += lcp(a+cnt, b+cnt, L, A)
                    break
            return res

        def get_lcp_brute_force():
            res = ""
            for i in range(1, N):
                a, b = s[L[i - 1]:], s[L[i]:]
                cnt = 0
                for k in range(min(len(a), len(b))):
                    if a[k] == b[k]:
                        cnt += 1
                    else:
                        break
                if cnt > len(res):
                    res = s[L[i]: L[i]+cnt]
            return res
        # print('golden: ', sorted(L, key=lambda i: s[i:]))
        # print('actual: ', L)

        def get_lcp():
            res = ""
            for i in range(1, N):
                l = lcp(L[i-1], L[i], L, A)
                if l > len(res):
                    res = s[L[i]: L[i]+l]
            return res

        res = get_lcp()
        # print('golden: ', get_lcp_brute_force())
        # print('actual: ', res)
        return res


if __name__ == "__main__":
    s = Solution()
    print('"' + s.longestDupSubstring(input().strip('"')) + '"')
    # assert s.longestDupSubstring("banana") == "ana"
    

