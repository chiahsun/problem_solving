#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const bool debug = true;

const int M = 100+5;
int A[M], B[M];

std::vector<int> visited[M][M];

void print_lis(const std::vector<int> & lis) {
    printf("lis : ");
    for (auto x : lis)
        printf("%d ", x);
    printf("\n");
}

void update_lis(int x, std::vector<int> & lis) {
    auto it = (lis.size() == 0 or lis.back() < x) ? lis.end() : std::lower_bound(lis.begin(), lis.end(), x);
    if (it == lis.end()) lis.push_back(x);
    else if (*it != x) *it = x;
}

void merge_jlis(int x, int y) {
    if (debug)
        printf("call %d %d\n", x, y);

    if (x != 0 and y != 0 and visited[x][y].size() == 0) {
        merge_jlis(x-1, y);
        merge_jlis(x, y-1);
    } else if (x != 0 and visited[x-1][y].size() == 0) merge_jlis(x-1, y);
      else if (y != 0 and visited[x][y-1].size() == 0) merge_jlis(x, y-1);

    std::vector<int> jlis;

    if (debug)
        printf("execute %d %d\n", x, y);
    if (x == 0 and y == 0) {
        if (A[0] == B[0]) {
            jlis.push_back(A[0]);
        } else {
            jlis.push_back(std::min(A[0], B[0]));
            jlis.push_back(std::max(A[0], B[0]));
        }
    } else if (x == 0) {
        jlis = visited[0][y-1];
        update_lis(B[y], jlis);
    } else if (y == 0) {
        jlis = visited[x-1][0];
        update_lis(A[x], jlis);
    } else {
        if (A[x] > B[y]) {
            jlis = visited[x-1][y];
            update_lis(A[x], jlis);
        } else {
            jlis = visited[x][y-1];
            update_lis(B[y], jlis);
        }
    }

    visited[x][y] = jlis;
    if (debug)
        print_lis(jlis);
}

int main() {
    int nCase, N1, N2;
    scanf("%d", &nCase);
    while (nCase--) {

        scanf("%d%d", &N1, &N2);
        for (int i = 0; i < N1; ++i) scanf("%d", A+i);
        for (int i = 0; i < N2; ++i) scanf("%d", B+i);

        if (debug) {
            for (int i = 0; i < N1; ++i) printf("%d ", A[i]); printf("\n");
            for (int i = 0; i < N2; ++i) printf("%d ", B[i]); printf("\n");
        }

        memset(visited, false, sizeof(visited));
        
        merge_jlis(N1-1, N2-1);

        printf("%lu\n", visited[N1-1][N2-1].size());
    }
    return 0;
}
