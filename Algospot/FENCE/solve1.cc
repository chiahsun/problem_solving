#include <cstdio>
#include <algorithm>

const int M = 20000+5;
const int INF = 1 << 29; 
int F[M];

void cut_fence(int cur_height, int begin, int end, int & max_area) {
    max_area = std::max(max_area, (end-begin) * cur_height);

    int next_height = INF;
    
    for (int i = begin; i < end; ++i) {
        if (F[i] > cur_height)
            next_height = std::min(next_height, F[i]);
    }

    if (next_height != INF) {
        int cur_begin = begin;
        for (int now = begin; now < end; ++now) {
            if (F[now] < next_height) {
                cut_fence(next_height, cur_begin, now, max_area);
                while (now < end and F[now] < next_height) ++now;
                if (now == end) { 
                    cur_begin = now; break; 
                }
                cur_begin = now;
            }
        }

        if (cur_begin != end)
            cut_fence(next_height, cur_begin, end, max_area);
    }
}

int main() {
    int nCase, nFence;
    scanf("%d", &nCase);

    while (nCase--) {
        scanf("%d", &nFence);
        for (int i = 0; i < nFence; ++i) scanf("%d", F+i);

        int max_area = 0;
        cut_fence(0, 0, nFence, max_area);
        printf("%d\n", max_area);
    }

    return 0;
}
