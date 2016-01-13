#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cassert>
#include <algorithm>

const int M = 5;
int city[M][M];

int p[5];

bool is_office(int oid) {
    for (int i = 0; i < 5; ++i)
        if (p[i] == oid)
            return true;
    return false;
}

// improvement: pass bound
int compute(int bound) {
    int res = 0;
    for (int i = 0; i < 5; ++i)
        for (int k = 0; k < 5; ++k) {
            bool found = false;
            for (int d = 0; (not found) and d < 10; ++d) {
                for (int oid = 0; oid < 25; ++oid) {
                    if (is_office(oid)) {
                        int oidx = oid/5;
                        int oidy = oid - oidx * 5;
                        if ((abs(i - oidx) + abs(k - oidy)) == d) {
                            res += (city[i][k] * d);
                            found = true;
                            break;
                        }
                    }
                }
            }
            if (res >= bound)
                return res+1;

        }
    return res;
}


int main() {
    int nCase, nCity;
    scanf("%d", &nCase);

    while (nCase--) {
        scanf("%d", &nCity);
        memset(city, 0, sizeof(city));

        while (nCity--) {
            int x, y, population;
            scanf("%d%d%d", &x, &y, &population);
            city[x][y] = population;
        }

        int vmin = INT_MAX;
        int ans[5] = {0, 1, 2, 3, 4};
        for (p[0] = 0     ; p[0] < 25-4; ++p[0])
        for (p[1] = p[0]+1; p[1] < 25-3; ++p[1])
        for (p[2] = p[1]+1; p[2] < 25-2; ++p[2])
        for (p[3] = p[2]+1; p[3] < 25-1; ++p[3])
        for (p[4] = p[3]+1; p[4] < 25  ; ++p[4]) {
            int val = compute(vmin);
#if 0
            printf("cost: %d | ", val);
            for (int i = 0; i < 5; ++i)
                 printf(" %d",  p[i]);
            printf("\n");
#endif
            if (val < vmin) { 
                vmin = val;
                for (int i = 0; i < 5; ++i)
                    ans[i] = p[i];
            }
        }

        for (int i = 0; i < 5; ++i)
            printf("%s%d", (i != 0 ? " " : ""), ans[i]);
        printf("\n");
    }
    return 0;
}
