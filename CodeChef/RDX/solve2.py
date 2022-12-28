def solve(A):
    N = len(A)
    L = list(range(N))

    def get_num_digits(a):
        cnt = 1
        while a > 10:
            a //= 10
            cnt += 1
        return cnt

    def mod_by(a, pos):
        while a > 0 and pos > 0:
            a //= 10; pos -= 1
        return a % 10

    def radix_sort(begin, end, pos):
        R = 10 # 0-9
        cnt, M = [0] * (R+1), [0] * (end-begin)
        for i in range(end-begin):
            a = M[i] = mod_by(A[L[i+begin]], pos)
            cnt[a+1] += 1
        for i in range(2, R):
            cnt[i] += cnt[i-1]
        new_index = [0] * (end-begin)
        for i, index in enumerate(L[begin:end]):
            new_index[cnt[M[i]]] = index
            cnt[M[i]] += 1
        for i in range(begin, end):
            L[i] = new_index[i-begin]
        return cnt[:R]

    def msd_radix_sort(begin, end, pos):
        if begin+1 >= end:
            return
        CNT = radix_sort(begin, end, pos)
        if pos == 0:
            return
        cur = 0
        for cnt in CNT:
            if cnt > cur:
                msd_radix_sort(begin+cur, begin+cnt, pos-1)
                cur = cnt
    # W: 1000000000
    # print(radix_sort(0, N, 0))
    msd_radix_sort(0, N, get_num_digits(max(A)))
    print(" ".join(map(lambda i: str(A[i]), L)))


if __name__ == "__main__":
    _ = int(input())
    A = list(map(int, input().strip().split()))
    solve(A)
