#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const bool debug = false;

const int M = 100+5;
int A[M], B[M];

std::vector<int> visited[M][M];

void print_lis(const std::vector<int> & lis, int x, int y) {
    for (int i = 0; i < x; ++i)
        printf("%d ", A[i]); 
    printf("\n");
    for (int i = 0; i < y; ++i)
        printf("%d ", B[i]); 
    printf("\n");
    printf("lis : ");
    for (auto x : lis)
        printf("%d ", x);
    printf("\n\n");
}

void update_lis(int x, std::vector<int> & lis) {
    auto it = (lis.size() == 0 or lis.back() < x) ? lis.end() : std::lower_bound(lis.begin(), lis.end(), x);
    if (it == lis.end()) lis.push_back(x);
    else if (*it != x) *it = x;
}

void merge_jlis(int x, int y) {
    if (debug)
        printf("call %d %d\n", x, y);

    if ((x == 0 and y == 0) or visited[x][y].size() != 0) return;
    if (x != 0) merge_jlis(x-1, y);
    if (y != 0) merge_jlis(x, y-1);

    if (x != 0) {
        std::vector<int> lis = visited[x-1][y];
        update_lis(A[x-1], lis);
        if (lis.size() > visited[x][y].size() or (lis.size() == visited[x][y].size() and lis.back() < visited[x][y].back()))
            visited[x][y] = lis;
    }

    if (y != 0) {
        std::vector<int> lis = visited[x][y-1];
        update_lis(B[y-1], lis);
        if (lis.size() > visited[x][y].size() or (lis.size() == visited[x][y].size() and lis.back() < visited[x][y].back()))
            visited[x][y] = lis;
    }

    if (debug)
        print_lis(visited[x][y], x, y);
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

        for (int i = 0; i <= N1; ++i)
            for (int k = 0; k <= N2; ++k)
                visited[i][k].clear();
        
        merge_jlis(N1, N2);

        printf("%lu\n", visited[N1][N2].size());
    }
    return 0;
}
