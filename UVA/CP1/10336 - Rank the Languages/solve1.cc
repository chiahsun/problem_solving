#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int M = 1000;
char world[M][M];
bool visited[M][M];
int cnt[26];
    
int nCase, nRow, nCol;

void dfs(int x, int y, char c) {
    visited[x][y] = true;
    const int SZ = 4;
    const int dx[SZ] = {1, -1, 0, 0};
    const int dy[SZ] = {0, 0, 1, -1};
    for (int i = 0; i < SZ; ++i) {
        int nx = x+dx[i], ny = y+dy[i];
        if (nx >= 0 and nx < nRow and ny >= 0 and ny < nCol and (not visited[nx][ny]) and world[nx][ny] == c) 
            dfs(nx, ny, c);
    }
}

struct Language {
    char _c;
    int _nSpoken;
    Language(char c, int nSpoken) : _c(c), _nSpoken(nSpoken) { }
    bool operator < (const Language & rhs) const {
        if (_nSpoken != rhs._nSpoken) return _nSpoken > rhs._nSpoken;
        return _c < rhs._c;
    }
};

int main() {
    int posWorld = 1;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d%d", &nRow, &nCol);
        for (int i = 0; i < nRow; ++i)
            scanf("%s", world[i]);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < nRow; ++i)
            for (int k = 0; k < nCol; ++k)
               visited[i][k] = false; 
        for (int i = 0; i < nRow; ++i)
            for (int k = 0; k < nCol; ++k) {
                if (not visited[i][k]) {
                    ++cnt[world[i][k] - 'a'];
                    dfs(i, k, world[i][k]);
                }
            }
        std::vector<Language> vecLang;
        for (int i = 0; i < 26; ++i)
           if (cnt[i])
               vecLang.push_back(Language(i+'a', cnt[i]));
        std::sort(vecLang.begin(), vecLang.end());
        printf("World #%d\n", posWorld++);
        for (const auto & lang : vecLang)
            printf("%c: %d\n", lang._c, lang._nSpoken);

    }

    return 0;
}
