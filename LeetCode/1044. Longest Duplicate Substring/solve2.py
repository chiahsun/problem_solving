# banana
# 012345
# L: [5, 3, 1, 0, 4, 2]
       
# 0   a      5 
# 1   ana    3
# 2   anana  1
# 3   banana 0
# 4   na     4
# 5   nana   2

def suffix_sort(s):
    def normalize(A):
        s = list(sorted(list(set(A))))
        d = {s[i]: i for i in range(len(s))}
        return list(map(lambda a: d[a], A)), len(s) == len(A)

    N, d = len(s), 1
    order, done = normalize(list(s))
    L, A = [0] * N, [[] for _ in range(N)]
    for i in range(N): 
        A[i].append(order[i])
    while not done:
        nxt = [order[i] * (N+1) + (order[i+d] if i+d < N else -1) for i in range(N)]  # Use N+1 since we have -1
        order, done = normalize(nxt)
        for i in range(N): 
            A[i].append(order[i])
        d *= 2

    AA = [None] * N 
    for i in range(N):
        pos = order[i]
        L[pos] = i
        AA[pos] = A[i]
    return L, order, AA

def get_common_prefix(s, L, R, A, p, q):
    M, N = len(A[0]), len(s)
    if A[p][0] != A[q][0]:
        return 0
    msb = 0
    for i in range(1, M):
        if A[p][i] == A[q][i]:
            msb = i
        else:
            break
    cnt = int(2 ** msb)
    if cnt == 0 or msb == M-1 or L[p]+cnt >= N or L[q]+cnt >= N:
        return cnt
    cnt += get_common_prefix(s, L, R, A, R[L[p]+cnt], R[L[q]+cnt])
    return cnt


class Solution:
    def longestDupSubstring(self, s: str) -> str:
        N, res = len(s), ""
        L, R, A = suffix_sort(s)

        for i in range(1, N):
            l = get_common_prefix(s, L, R, A, i-1, i)
            if l > len(res):
                res = s[L[i]: L[i]+l]
        return res
