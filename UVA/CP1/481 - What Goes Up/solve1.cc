#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> A, lis, lis_pos, lis_prev;
int last_pos;

void print_prev(int pos) {
    if (lis_prev[pos] != pos)
        print_prev(lis_prev[pos]);
    printf("%d\n", A[pos]);
}

int main() {
    int x;
    for (int pos = 0; scanf("%d", &x) == 1; ++pos) {
        A.push_back(x);
        lis_prev.push_back(pos);
        if (lis.size() == 0 or lis.back() < x) {
            lis.push_back(x);
            lis_pos.push_back(pos);

            if (lis.size() > 1) {
                lis_prev[pos] = lis_pos[lis.size()-2];
            }
            last_pos = pos;
        } else {
            auto it = std::lower_bound(lis.begin(), lis.end(), x);
            lis_pos[it-lis.begin()] = pos;
            if (it != lis.begin())
                lis_prev[pos] = lis_pos[it-lis.begin()-1]; 
            if (*it != x) {
                *it = x;
                if (++it == lis.end()) 
                    last_pos = pos;
            } 
        }
#if 0
        printf("seq     : ");
        for (auto x : A) printf("%3d", x);
        printf("\n");
        printf("pos     : ");
        for (int i = 0; i <= pos; ++i) printf("%3d", i);
        printf("\n");
        printf("lis_prev: ");
        for (auto x : lis_prev) printf("%3d", x);
        printf("\n");
        printf("lis :");
        for (auto x : lis) printf(" %d", x);
        printf("\n");
        printf("lis_pos: ");
        for (auto x : lis_pos) printf(" %d", x);
        printf("\n\n");
#endif
    }
    printf("%lu\n-\n", lis.size());
    print_prev(last_pos);
    return 0;
}
