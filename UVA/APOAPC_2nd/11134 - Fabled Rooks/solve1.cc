#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

const bool debug = false;
const int M = 5000+5;
int N;

struct Bound {
    int _id; 
    int _left, _right;
    Bound() { }
    Bound(int id, int l, int r) : _id(id), _left(l), _right(r) { }
    bool operator < (const Bound & rhs) const {
        return (_left < rhs._left) || (_left == rhs._left and _right < rhs._right);
//        return (_right < rhs._right) || (_right == rhs._right and _left < rhs._left);
    }
    int left() const { return _left; }
    int right() const { return _right; }
    int id() const { return _id; }
};

struct BoundRightCompare {
    const Bound* _p;
    BoundRightCompare(const Bound* p) : _p(p) { }
    bool operator () (int a, int b) const {
        return (_p[a].right() > _p[b].right()) or (_p[a].right() == _p[b].right() and _p[a].left() > _p[b].left());
    }
};

std::pair<int, int> R[M];
Bound X[M];
Bound Y[M];


int S[M];

bool check(Bound* a, bool is_first = true) {
    std::priority_queue<int, std::vector<int>, BoundRightCompare> pq((BoundRightCompare(a)));
    for (int i = 1, k = 0; i <= N; ++i) {
        while (a[k].left() == i) {
            pq.push(k);
            if (debug)
                printf("@ %d : push (%d, %d) in pq\n", i, a[k].left(), a[k].right());
            ++k;
        }
        if (pq.size() == 0) {
            if (debug)
                printf(" fail # %d\n", i);
            return false;
        }
        else {
            int t = pq.top(); pq.pop();
            if (debug)
                printf("# %d : cur top (%d, %d)\n", i, a[t].left(), a[t].right());
            if (not(a[t].left() <= i and a[t].right() >= i)) {
                if (debug)
                    printf(" fail # %d for top (%d, %d)\n", i, a[t].left(), a[t].right());
                return false;
            }
            if (is_first)
                R[a[t].id()].first = i;
            else
                R[a[t].id()].second = i;
        }
    }
#if 0 
    for (int i = 0, pos = 1; i < N; ++i) {
        while ()
        int r = a[i].right();
        pos = std::max(pos, a[i].left());
  //      printf("left : %d, right : %d , pos : %d\n", a[i].left(), r, pos);
        if (pos > r)
            return false;
        if (is_first)
            R[a[i].id()].first = pos++;
        else
            R[a[i].id()].second = pos++;
    }
#endif
    return true;
}

int main() {
    while (scanf("%d", &N) == 1 and N) {
        for (int i = 0; i < N; ++i) {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
//            printf("%d %d %d %d\n", x1, y1, x2, y2);
            X[i] = Bound(i, x1, x2);
            Y[i] = Bound(i, y1, y2);
        }

        std::sort(X, X+N);
        bool x_ok = check(X);
        if (x_ok)
            std::sort(Y, Y+N);
        bool y_ok = x_ok and check(Y, false);
#if 0
        for (int i = 0; i < N; ++i)
            printf("%d %d\n", X[i].left(), X[i].right());
#endif
        if (x_ok and y_ok) {
            for (int i = 0; i < N; ++i)
                printf("%d %d\n", R[i].first, R[i].second);
        } else {
            printf("IMPOSSIBLE\n");
        }

    }

    return 0;
}
