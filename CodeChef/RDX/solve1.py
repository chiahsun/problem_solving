def solve(A):
    N = len(A)
    L = list(range(N))

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
        return sum(M) > 0

    # W: 1000000000
    for pos in range(11):
        if not radix_sort(0, N, pos):
            break

    print(" ".join(map(lambda i: str(A[i]), L)))


if __name__ == "__main__":
    _ = int(input())
    A = list(map(int, input().strip().split()))
    solve(A)
