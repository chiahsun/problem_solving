#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

struct Box {
    int _id;
    std::vector<int> _vec;
    Box(int id, const std::vector<int> & v) : _id(id), _vec(v) { }
    int & operator [] (int x) { return _vec[x]; }
    const int & operator [] (int x) const { return _vec[x]; }
    int size() const { return _vec.size(); }
    void push_back(int x) { _vec.push_back(x); }
};

struct BoxCompare {
    bool operator () (const Box & a, const Box & b) const {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i])
                return a[i] < b[i];
        }
        return false;
    }
};

struct StrictLess {
    bool operator () (const Box & a, const Box & b) const {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] >= b[i])
                return false;
        }
        return true;
    }
};

const int M = 30 + 5;
int lis[M];
int prev[M];

void print_sol(int x, const std::vector<Box> & vecBox) {
    std::stack<int> st;
    while (x != prev[x]) {
        st.push(x);
        x = prev[x];
    }
    printf("%d", vecBox[x]._id);

    while (not st.empty()) {
        printf(" %d", vecBox[st.top()]._id); st.pop();
    }
    printf("\n");
}

int main() {
    int nBox, length;
    while (scanf("%d%d", &nBox, &length) == 2) {
        std::vector<Box> vecBox;
        for (int i = 0; i < nBox; ++i) {
            std::vector<int> v;
            for (int k = 0; k < length; ++k) {
                int x;
                scanf("%d", &x);
                v.push_back(x);
            }
            std::sort(v.begin(), v.end());
            vecBox.push_back(Box(i+1, v));
        }

        std::sort(vecBox.begin(), vecBox.end(), BoxCompare());

#if 0
        for (int i = 0; i < vecBox.size(); ++i) {
            for (const auto & x : vecBox[i]) {
                printf("%d ", x);
            }
            printf("\n");
        }
        int cnt = 0;
        for (int i = 1; i < vecBox.size(); ++i) {
            if (BoxCompare()(vecBox[i-1], vecBox[i]))
                ++cnt;
        }
#endif
        int maxl = 1, max_pos = 0;
        std::fill(lis, lis+M, 1);
        for (int i = 0; i < M; ++i)
            prev[i] = i;
        for (int i = 0; i < vecBox.size(); ++i) {
            for (int k = i+1; k < vecBox.size(); ++k) {
                if (StrictLess()(vecBox[i], vecBox[k]) and (lis[i]+1 > lis[k])) {
                    lis[k] = lis[i]+1;
                    prev[k] = i;
                    if (lis[k] > maxl) {
                        maxl = lis[k];
                        max_pos = k;
                    }
                }
            }
        }
        printf("%d\n", maxl);
        print_sol(max_pos, vecBox);
    }
    return 0;
}
