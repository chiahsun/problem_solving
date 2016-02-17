#include <cstdio>

const int M = 20+5;
int board[M][M];

int main() {
    int nCase, N;
    scanf("%d", &nCase);
    printf("%d\n", nCase);

    while (nCase--) {
        scanf("%d", &N);
        printf("%d\n", N);
        for (int i = 0; i < N; ++i) {
            for (int k = 0; k < N; ++k) {
                scanf("%d", &board[i][k]);
                if (k != 0) printf(" ");
                printf("%d", board[i][k] ? 1 : 0);
            }
            printf("\n");
        }
        int n_constraint = 0;
        for (int i = 0; i < N; ++i)
            for (int k = 0; k < N; ++k) {
                if ((board[i][k] == 0) and (i+1 < N) and (board[i+1][k] != 0)) ++n_constraint; 
                if ((board[i][k] == 0) and (k+1 < N) and (board[i][k+1] != 0)) ++n_constraint;
            }
        printf("%d\n", n_constraint);
        for (int i = 0; i < N; ++i)
            for (int k = 0; k < N-1; ++k) {
                if (not board[i][k] and board[i][k+1]) {
                    int sum = 0;
                    int t = k+1;
                    while (t < N and board[i][t]) {
                        sum += board[i][t];
                        ++t;
                    }
                    printf("%d %d 0 %d\n", i+1, k+1, sum);
                }
            }
        for (int i = 0; i < N-1; ++i)
            for (int k = 0; k < N; ++k) {
                if (not board[i][k] and board[i+1][k]) {
                    int sum = 0;
                    int t = i+1;
                    while (t < N and board[t][k]) {
                        sum += board[t][k];
                        ++t;
                    }
                    printf("%d %d 1 %d\n", i+1, k+1, sum);
                }
            }
    }

    return 0;
}
