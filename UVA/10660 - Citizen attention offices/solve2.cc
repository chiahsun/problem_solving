#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cassert>
#include <algorithm>

const int M = 5;
int city[M][M];
int p_dist_map[5][M][M]; 
int cur_dist_map[5][M][M]; 
int p[5]; 

void get_p_dist_map(int pid) {
    int oid = p[pid];
    int oidx = oid/5;
    int oidy = oid - oidx * 5;
    for (int i = 0; i < 5; ++i)
        for (int k = 0; k < 5; ++k) {
            if (city[i][k] > 0)
                p_dist_map[pid][i][k] = (abs(i - oidx) + abs(k - oidy));
            else
                p_dist_map[pid][i][k] = 0; 
        }
}

void compute_cur_dist_map(int pid) {
    get_p_dist_map(pid);
    if (pid == 0)
        memcpy(cur_dist_map, p_dist_map, sizeof(int) * M * M);
    else {
        memcpy(cur_dist_map+pid, cur_dist_map+pid-1, sizeof(int) * M * M);
        for (int i = 0; i < 5; ++i) 
            for (int k = 0; k < 5; ++k) {
                cur_dist_map[pid][i][k] = std::min(cur_dist_map[pid][i][k], p_dist_map[pid][i][k]);
            }
    }
}

int compute(int bound) {
    int res = 0;
    for (int i = 0; i < 5; ++i)
        for (int k = 0; k < 5; ++k) {
            res += (cur_dist_map[4][i][k] * city[i][k]);
            if (res >= bound)
                return res + 1;
        }
    return res;
}


int main() {
    int nCase, nCity;
    scanf("%d", &nCase);

    while (nCase--) {
        scanf("%d", &nCity);
        memset(city, 0, sizeof(city));
        memset(cur_dist_map, 100, sizeof(cur_dist_map));

        while (nCity--) {
            int x, y, population;
            scanf("%d%d%d", &x, &y, &population);
            city[x][y] = population;
        }

        int vmin = INT_MAX;
        int ans[5];
        for (p[0] = 0 ; p[0] < 25-4; ++p[0]) {
            compute_cur_dist_map(0);
            for (p[1] = p[0]+1; p[1] < 25-3; ++p[1]) { 
                compute_cur_dist_map(1);
                for (p[2] = p[1]+1; p[2] < 25-2; ++p[2]) {
                    compute_cur_dist_map(2);
                    for (p[3] = p[2]+1; p[3] < 25-1; ++p[3]) {
                        compute_cur_dist_map(3);
                        for (p[4] = p[3]+1; p[4] < 25  ; ++p[4]) {
                            compute_cur_dist_map(4);
                            int val = compute(vmin);
                            if (val < vmin) { 
#if 0
                            printf("cost: %d | ", val);
                            for (int i = 0; i < 5; ++i)
                                printf(" %d",  p[i]);
                            printf("\n");
#endif
                                vmin = val;
                                for (int i = 0; i < 5; ++i)
                                    ans[i] = p[i];
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 5; ++i)
            printf("%s%d", (i != 0 ? " " : ""), ans[i]);
        printf("\n");
    }
    return 0;
}
