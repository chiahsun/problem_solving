#include <cstdio>
#include <utility>
#include <algorithm>

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
std::pair<int, int> R[M];
Bound X[M];
Bound Y[M];

int S[M];

bool check(Bound* a, bool is_first = true) {
    int nrook = 0;
    for (int i = 0, pos = 1; i < N; ++i) {
        int r = a[i].right();
        ++nrook;
        if (nrook > r) 
            return false;
        pos = std::min(pos, a[i].left());
        if (is_first)
            R[a[i].id()].first = pos++;
        else
            R[a[i].id()].second = pos++;
    }
    return true;
}

int main() {
    while (scanf("%d", &N) == 1 and N) {
        for (int i = 0; i < N; ++i) {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            X[i] = Bound(i, x1, x2);
            Y[i] = Bound(i, y1, y2);
        }

        std::sort(X, X+N);
        std::sort(Y, Y+N);
#if 0
        for (int i = 0; i < N; ++i)
            printf("%d %d\n", X[i].left(), X[i].right());
#endif
        if (check(X) and check(Y, false)) {
            for (int i = 0; i < N; ++i)
                printf("%d %d\n", R[i].first, R[i].second);
        } else {
            printf("IMPOSSIBLE\n");
        }

    }

    return 0;
}
