#include <cstdio>
#include <algorithm>

const int MAX = 1000 + 5;
struct Task {
    int _b, _j;
    Task(){}
    Task(int b, int j) : _b(b), _j(j) { }
    bool operator < (const Task & rhs) const { return _j > rhs._j; }
} T[MAX];

int main() {
    int n;
    int posCase = 1;
    while (scanf("%d", &n) && n) {
        int b, bsum = 0;
        int j, jmin = 10000;
        int cost = 0;
        for (int i = 0; i < n; ++i) scanf("%d%d", &T[i]._b, &T[i]._j);
        std::sort(T, T+n);
        for (int i = 0; i < n; ++i) {
            int b = T[i]._b;
            int j = T[i]._j;
            bsum += b;
            cost = std::max(bsum + j, cost);
        }

        printf("Case %d: %d\n", posCase++, cost);
    }
    return 0;
}
