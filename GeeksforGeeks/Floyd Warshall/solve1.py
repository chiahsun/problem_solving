from functools import reduce
import operator

T = int(input())

for i in range(T):
    N = int(input())
    I = list(map(int, input().strip().split(" ")))
    V = [[0] * N for _ in range(N)]
    D = [[0x7FFFFFFFF] * N for _ in range(N)]
    pos = 0
    for i in range(N):
        for k in range(N):
            D[i][k] = V[i][k] = I[pos]
            pos += 1

    for i in range(N):
        for x in range(N):
            for y in range(N):
                new_dist = D[x][i] + D[i][y]
                if new_dist < D[x][y]:
                    D[x][y] = new_dist

    ans = " ".join([str(x) for row in D for x in row])
    #ans = " ".join(map(str, reduce(operator.add, D)))
    print(ans)

