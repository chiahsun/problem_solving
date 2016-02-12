#include <cstdio>
#include <vector>
#include <algorithm>

const int M = 100+5;
int A[M], B[M];

int merge_list(const std::vector<int> & v1, int sz1, const std::vector<int> & v2, int sz2) {
    int size = 0, last = -(1 << 29);
    for (int pos1 = 0, pos2 = 0; pos1 < sz1 or pos2 < sz2;) {
        int cur;
        if (pos2 >= sz2 or (pos1 < sz1 and v1[pos1] <= v2[pos2])) {
            cur = v1[pos1]; ++pos1;
        } else {
            cur = v2[pos2]; ++pos2;
        }
        if (cur != last) {
            ++size;
            last = cur;
        }
    }

    return size;
}

int update_lis(int x, std::vector<int> & lis) {
    auto it = std::lower_bound(lis.begin(), lis.end(), x);
    size_t sz;
    if (it == lis.end()) {
        lis.push_back(x);
        sz = lis.size();
    } else if (*it != x) {
        *it = x;
        sz = it - lis.begin() + 1;
    } else {
        sz = it - lis.begin() + 1;
    }

    return sz;
}

int main() {
    int nCase, N1, N2;
    scanf("%d", &nCase);
    while (nCase--) {

        scanf("%d%d", &N1, &N2);
        for (int i = 0; i < N1; ++i) scanf("%d", A+i);
        for (int i = 0; i < N2; ++i) scanf("%d", B+i);
#if 0
        for (int i = 0; i < N1; ++i) printf("%d ", A[i]); printf("\n");
        for (int i = 0; i < N2; ++i) printf("%d ", B[i]); printf("\n");
#endif

        int jlis_size = 0;
        std::vector<int> lis1;
        for (int i = 0; i < N1; ++i) {

            int sz1 = update_lis(A[i], lis1);

            std::vector<int> lis2;
            for (int k = 0; k < N2; ++k) {
                int sz2 = update_lis(B[k], lis2);
                jlis_size = std::max(jlis_size, merge_list(lis1, sz1, lis2, sz2));
            } 
        }
        
        printf("%d\n", jlis_size);
    }
    return 0;
}
