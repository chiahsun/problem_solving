#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
const int M = 1025+5;
int S[M][M];

int main() {
    int nCase, strength, nPopulation;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d%d", &strength, &nPopulation);
        memset(S, 0, sizeof(S));
        int vmax = 0, vmax_x, vmax_y;

        for (int i = 0; i < nPopulation; ++i) {
            int xrat, yrat, nrat;
            scanf("%d%d%d", &xrat, &yrat, &nrat);
            for (int x = std::max(0, xrat-strength); x < std::min(M, xrat+strength+1); ++x) {
                for (int y = std::max(0, yrat-strength); y < std::min(M, yrat+strength+1); ++y) {
                    assert(x>=0 and x<M and y>=0 and y<M);
                    int cur = (S[x][y] += nrat);
                    if (cur > vmax or (cur == vmax and (x < vmax_x or (x == vmax_x and y < vmax_y)))) {
                        vmax = cur;
                        vmax_x = x;
                        vmax_y = y;
                    } 
                }
            }
        }

        printf("%d %d %d\n", vmax_x, vmax_y, vmax);
    }
    return 0;
}
