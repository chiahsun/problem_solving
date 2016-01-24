#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
const int M = 1025+5;
int S[M][M];
int P[20000+5][2];
int visited[M][M];
int strength, nPopulation;
int left_most, right_most, top_most, bottom_most;

int get_sum_of_row(int x, int y) {
    assert(x >= 0 and x <= right_most);
    int sum = 0;
    for (int k = std::max(bottom_most, y-strength); k <= std::min(y+strength, top_most); ++k)
        sum += S[x][k];
    return sum;
}

int get_sum_of_col(int x, int y) {
    assert(y >= 0 and y <= top_most);
    int sum = 0;
    for (int i = std::max(left_most, x-strength); i <= std::min(x+strength, right_most); ++i)
        sum += S[i][y];
    return sum;
}

int compute_sum(int x, int y) {
    int sum = 0;
#if 1 
    if (x-1 >= 0 and visited[x-1][y]) {
        int prev_sum = (x-1-strength >= left_most) ? get_sum_of_row(x-1-strength, y) : 0;
        int next_sum = (x+strength <= right_most) ? get_sum_of_row(x+strength, y) : 0;
        return visited[x-1][y]-prev_sum+next_sum;
    }
    if (x+1 <= right_most and visited[x+1][y]) {
        int prev_sum = (x+1+strength <= right_most) ? get_sum_of_row(x+1+strength, y) : 0;
        int next_sum = (x-strength >= 0) ? get_sum_of_row(x-strength, y) : 0;
        return visited[x+1][y]-prev_sum+next_sum;
    }
#endif
    if (y-1 >= 0 and visited[x][y-1]) {
        int prev_sum = (y-1-strength >= bottom_most) ? get_sum_of_col(x, y-1-strength) : 0;
        int next_sum = (y+strength<=top_most) ? get_sum_of_col(x, y+strength) : 0;
        return visited[x][y-1]-prev_sum+next_sum;
     }
    if (y+1 <= top_most and visited[x][y+1]) {
        int prev_sum = (y+1+strength <= top_most) ? get_sum_of_col(x, y+1+strength) : 0;
        int next_sum = (y-strength >= 0) ? get_sum_of_row(x, y-strength) : 0;
        return visited[x][y+1]-prev_sum+next_sum;
    }

    for (int i = std::max(left_most, x-strength); i <= std::min(x+strength, right_most); ++i)
        for (int k = std::max(bottom_most, y-strength); k <= std::min(y+strength, top_most); ++k)
            sum += S[i][k];
    return sum;
}

int main() {
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d%d", &strength, &nPopulation);
        memset(S, 0, sizeof(S));
        memset(visited, 0, sizeof(visited));
        left_most = M, right_most = 0, top_most = 0, bottom_most = M;
        for (int i = 0; i < nPopulation; ++i) {
            int x, y, nrat;
            scanf("%d%d%d", &x, &y, &nrat);
            left_most = std::min(x, left_most);
            right_most = std::max(x, right_most);
            top_most = std::max(y, top_most);
            bottom_most = std::min(y, bottom_most);
            S[x][y] = nrat;
            P[i][0] = x;
            P[i][1] = y;
        }

        int vmax = 0, vmax_x = 0, vmax_y = 0;
        for (int posPopulation = 0; posPopulation < nPopulation; ++posPopulation) {
            int x = P[posPopulation][0];
            int y = P[posPopulation][1];
            if (not visited[x][y]) {
                for (int i = std::max(0, x-strength); i <= std::min(right_most, x+strength); ++i)
                    for (int k  = std::max(0, y-strength); k <= std::min(top_most, y+strength); ++k) {
                        if (not visited[i][k]) {
                            int sum = visited[i][k] = compute_sum(i, k);
                            if (sum > vmax) {
                                vmax = sum;
                                vmax_x = i;
                                vmax_y = k;
                            }
                        }
                    }
            }
        }

        printf("%d %d %d\n", vmax_x, vmax_y, vmax);
    }
    return 0;
}
