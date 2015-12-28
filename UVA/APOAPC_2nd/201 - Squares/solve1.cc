#include <cstdio>
#include <cstring>

// const bool debug = true;
const bool debug = false;

const int MAX = 9+3;
bool H[MAX][MAX];
bool V[MAX][MAX];
int L[MAX];

int main() {

    int N, numLine;
    int posProblem = 1;
    while (scanf("%d%d", &N, &numLine) == 2) {
        memset(H, 0, sizeof(H));
        memset(V, 0, sizeof(V));
        memset(L, 0, sizeof(L));

        if (debug)
            printf("numSize = %d, numLine = %d\n", N, numLine);
        while (numLine--) {
            getchar();
            int x, y;
            char dir;
            scanf("%c%d%d", &dir, &x, &y);
            if (dir == 'H') {
                if (debug)
                    printf("Add H (%d, %d)\n", x, y);
                H[x][y] = true;
            } else {
                if (debug)
                    printf("Add V (%d, %d)\n", y, x);
                V[y][x] = true;
            }
        }


        for (int len = 1; len < N; ++len) {
            if (debug)
                printf("start length = %d\n", len);
            for (int x = 1; x <= N-len; ++x) {
                for (int y = 1; y <= N-len; ++y) {
                    bool ok = true;
                    int x_end = x + len;
                    int y_end = y + len;
                    for (int i = 0; ok and i < len; ++i) {
                        ok &= H[x][y+i];
                        if (debug and !H[x][y+i])
                           printf("B(%d,%d) fails at H(%d,%d)\n", x, y, x, y+i);
                        ok &= H[x_end][y+i];
                        if (debug and !H[x_end][y+i])
                            printf("B(%d,%d) fails at H(%d,%d)\n", x, y, x_end, y+i);
                        ok &= V[x+i][y];
                        if (debug and !V[x+i][y])
                            printf("B(%d,%d) fails at V(%d,%d)\n", x, y, x+i, y);
                        ok &= V[x+i][y_end];
                        if (debug and !V[x+i][y_end])
                            printf("B(%d,%d) fails at V(%d,%d)\n", x, y, x+i, y_end);
                    }
                    if (ok) {
                        if (debug)
                            printf("Add B(%d, %d)\n", x, y);
                        ++L[len];
                    }
                }
            }
        }

        if (posProblem != 1) {
            printf("\n**********************************\n\n");
        } 
        printf("Problem #%d\n\n", posProblem);
        int sum = 0;
        for (int i = 1; i < N; ++i) {
            if (L[i] > 0) {
                printf("%d square (s) of size %d\n", L[i], i);
                sum += L[i];
            }
        }

        if (sum == 0) {
            printf("No completed squares can be found.\n");
        }
        ++posProblem;

    }

    return 0;
}
