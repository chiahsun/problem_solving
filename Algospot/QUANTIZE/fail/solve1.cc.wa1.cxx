#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>

const bool debug = false;

const int M = 100+5;
int nData, nVar;

int A[M];
int V[15];
int square(int x) { return x * x; }

int get_closest(int x) {
    auto it = std::lower_bound(V, V+nVar, x);
    if (it == V + nVar) return V[nVar-1];
    else if (it == V) return *it;
    else if (*it == x) return x;

    int now = *it;
    int prev = *(--it);
    if (abs(prev-x) <= abs(now-x)) return prev;
    return now;
}

int get_cost() {
    int cost = 0;
    for (int i = 0; i < nData; ++i)
        cost += square(A[i]-get_closest(A[i]));
    return cost;
}

bool is_valid(const std::vector<int> & v, int pos) {
    if (v[pos] < 1 or v[pos] > 1000) return false;
    if (pos != 0 and v[pos] <= v[pos-1]) return false;
    if (pos != v.size()-1 and v[pos] >= v[pos+1]) return false;
    return true;
}

int main() {
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d%d", &nData, &nVar);

        for (int i = 0; i < nData; ++i) scanf("%d", A+i);
        std::sort(A, A+nData);
        int step = nData/(nVar+1);
        std::vector<int> initial;
        for (int i = 0; i < nVar; ++i) {
            V[i] = A[std::min((i+1)*step, nData-1)];
            initial.push_back(V[i]);
        }

        std::queue<std::vector<int> > q;
        q.push(initial);

        int min_cost = 1<<29;
        while (not q.empty() and min_cost != 0) {
            std::vector<int> cur = q.front(); q.pop();
            for (int i = 0; i < nVar; ++i) V[i] = cur[i];
            int cur_cost = get_cost();
            if (debug) {
                for (int i = 0; i < nVar; ++i)
                    printf("%d ", V[i]);
                printf(" : cost %d\n", cur_cost);
            }

            if (cur_cost < min_cost) {
                min_cost = cur_cost;

                for (size_t i = 0; i < cur.size(); ++i) {
                    std::vector<int> next(cur);
                    next[i] += 1; 
                    if (is_valid(next, i)) q.push(next);
                    next[i] -= 2;
                    if (is_valid(next, i)) q.push(next);
                }
            }
        }

        printf("%d\n", min_cost);

    }
    return 0;
}
