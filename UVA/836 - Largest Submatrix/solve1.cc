#include <cstdio>
#include <cstring>
#include <algorithm>

void read_until_newline() { 
    char c;
    while (1) { 
        c = getchar();
        if (c == '\n' or c == EOF) break; 
    } 
}

const int M = 25+5;
// const int M = 30+5;
char map[M][M];
char buf[M];
char all[M][M][M][M];
const char NEQ = 'X';
int main() {
    int nCase;
    scanf("%d", &nCase);

    read_until_newline();
    read_until_newline();
    while (nCase--) {
        int nrow = 0;
        while (scanf("%[^\n]", map[nrow]) == 1) {
            getchar();
            ++nrow;
        }
        int ncol = strlen(map[0]);
//        printf("%d %d\n", nrow, ncol);

        for (int i = 0; i < M; ++i)
            for (int k = 0; k < M; ++k)
                for (int m = 0; m < M; ++m)
                    for (int p = 0; p < M; ++p)
                        all[i][k][m][p] = NEQ;
//        std::fill(all, all+sizeof(all), NEQ);
//        memset(all, NEQ, sizeof(all));

        int vmax = 0;
        char c;
        for (int xlen=1; xlen <= nrow; ++xlen)
            for (int xbegin=0; xbegin <= nrow-xlen; ++xbegin) {
                int xend = xbegin+xlen;
                for (int ylen=1; ylen <= ncol; ++ylen)
                    for (int ybegin=0; ybegin <= ncol-ylen; ++ybegin) {
                        int yend = ybegin+ylen;
                        if (xlen == 1 and ylen == 1) {
                            c = all[xbegin][xend][ybegin][yend] = map[xbegin][ybegin];
                            if (c == '1')
                                vmax = std::max(vmax, 1);
                        } else { 
                            if ((c = all[xbegin][xend][ybegin][yend-1]) == all[xbegin][xend][yend-1][yend] and (c == '1')) {
                                all[xbegin][xend][ybegin][yend] = c;
                                // printf("%d %d %d %d (%d, %d)\n", xbegin, xend, ybegin, yend, xlen, ylen);
                                vmax = std::max(xlen * ylen, vmax);
                            } 
                            if ((c = all[xbegin][xend-1][ybegin][yend]) == all[xend-1][xend][ybegin][yend] and (c =='1')) {
                                all[xbegin][xend][ybegin][yend] = c;
                                // printf("%d %d %d %d (%d, %d)\n", xbegin, xend, ybegin, yend, xlen, ylen);
                                vmax = std::max(xlen * ylen, vmax);
                            } 
                        }
                    }
            }
        printf("%d\n", vmax);
        if (nCase != 0)
            printf("\n");

        read_until_newline();
    }

    return 0;
}
