# https://www.geeksforgeeks.org/python-input-methods-competitive-programming/

def read_io():
    N, M = [int(x) for x in input().split()]
    A = [[] for _ in range(N)]
    for _ in range(M):
        f, t = [int(x) for x in input().split()]
        A[f].append(t)
        A[t].append(f)
    return N, A


def solve(N, A):
    visited, closed = [False] * N, [False] * N

    def has_cycle(x, parent):
        if closed[x]:
            return False
        if visited[x]:
            return True
        visited[x] = True
        for t in A[x]:
            if not closed[t] and t != parent and has_cycle(t, x):
                return True
        closed[x] = True
        return False

    for i in range(N):
        if not closed[i] and has_cycle(i, -1):
            return True
    return False


if __name__ == "__main__":
    print("Yes" if solve(*read_io()) else "No")
