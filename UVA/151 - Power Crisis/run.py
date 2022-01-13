def J(N, K):
    if N <= 1:
        return 1
    res = J(N-1, K) + K
    if res > N:
        res = res - N * ((res-1) // N)
    return res

K = 7
for i in range(1, 18):
    print("J(", i, ",", K, "): ", J(i, K))

