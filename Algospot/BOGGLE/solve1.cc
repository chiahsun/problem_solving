#include <cstdio>
#include <cstring>
#include <algorithm>

const int M = 5+1;
char board[M][M];
char query[50];

bool dp(int len) {
    bool available[2][M][M];
    memset(available, -1, sizeof(available));
    int cur_pos = 0;
    int nok = M*M;

    for (int pos = 0; pos < len; ++pos, cur_pos = 1-cur_pos) {
        // Reference: 
        //   http://stackoverflow.com/questions/1052818/create-a-pointer-to-two-dimensional-array
        bool (*cur)[M] = available[cur_pos];
        bool (*prev)[M] = available[1-cur_pos];
        memset(cur, 0, sizeof(available[0]));
        
        nok = 0;
        for (int x = 0; x < 5; ++x) {
            for (int y = 0; y < 5; ++y) {
                if (board[x][y] == query[pos]) {
                    const int SZ = 8;
                    const static int dx[SZ] = {1, 1, 1, 0, 0, -1, -1, -1};
                    const static int dy[SZ] = {1, 0, -1, 1, -1, 1, 0, -1};
                    for (int d = 0; d < SZ; ++d) {
                        int rx = x + dx[d];
                        int ry = y + dy[d];
                        if (rx >= 0 and rx < 5 and ry >= 0 and ry < 5 and prev[rx][ry]) {
                            cur[x][y] = true;
                            ++nok;
                            if (pos+1 == len) return true;
                            break;
                        }
                    }
                }
            }}
        if (not nok) return false;
    }
    return false;
}

int main() {
    int nCase, nQuery;
    scanf("%d", &nCase);

    while (nCase--) {
        for (int i = 0; i < 5; ++i)
            scanf("%s", board[i]);
        scanf("%d", &nQuery);
        while (nQuery--) {
            scanf("%s", query);
            int len = strlen(query);
            
            printf("%s %s\n", query, dp(len) ? "YES" : "NO");
        }
    }
    return 0;
}
