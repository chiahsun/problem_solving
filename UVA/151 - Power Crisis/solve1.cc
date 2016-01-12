#include <iostream>

const int M = 100 + 5;
int next[M];
int prev[M];

int remove(int pos) {
    int n_prev = prev[pos];
    int n_next = next[pos];

    next[n_prev] = n_next;
    prev[n_next] = n_prev;
    return n_next;
}

int main() {
    int N;
    while (scanf("%d", &N) == 1 and N) {
        for (int cycle = 1; cycle <= N; ++cycle) {
            for (int k = 1; k <= N; ++k) {
                next[k] = k+1;
                prev[k] = k-1;
            }
            next[N] = 1;
            prev[1] = N; 

            int nLeft = N;
            int pos = 1;
            while (nLeft > 1) {
                pos = remove(pos);
                --nLeft;
                for (int i = 0; i < cycle-1; ++i)
                    pos = next[pos];
            }
            if (pos == 13) {
                printf("%d\n", cycle);
                break;
            }
        }
    }

    return 0;
}
