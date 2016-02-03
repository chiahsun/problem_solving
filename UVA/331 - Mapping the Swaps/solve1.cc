#include <cstdio>
#include <algorithm>

char buf[2000];
int A[1000];

int dfs(const int & na) {
    int cnt = 0;
    int n_inversion = 0;
    for (int i = 0; i < na-1; ++i)
        if (A[i] > A[i+1]) {
            std::swap(A[i], A[i+1]);
            cnt += dfs(na);
            ++n_inversion;
            std::swap(A[i], A[i+1]);
        }
    if (n_inversion == 0) cnt = 1;
#if 0
    for (int i = 0; i < na; ++i)
        printf("%d ", A[i]);
    printf(" path (%d)\n", cnt);
#endif
    return cnt;
}

int main() {
    int posCase = 1, na;
    while (scanf("%d", &na) == 1 and na) {
        for (int i = 0; i < na; ++i) 
            scanf("%d", A+i);
        bool ordered = true;
        for (int i = 0; i < na-1; ++i)
            if (A[i] > A[i+1]) {
                ordered = false;
                break;
            }
#if 0 
        for (int i = 0; i < na; ++i)
            printf("%d ", A[i]);
        printf("\n");
#endif

        printf("There are %d swap maps for input data set %d.\n", (ordered ? 0 : dfs(na)), posCase++);

    }

    return 0;
}
