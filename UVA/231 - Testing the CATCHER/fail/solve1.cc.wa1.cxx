#include <vector>
#include <map>
#include <algorithm>

int a;
int main() {
    int posCase = 1;
    while (scanf("%d", &a) and a != -1) {
        std::map<int, int> m;
        m.insert(std::make_pair(a, 1));
        int vmax = 1;
        while (scanf("%d", & a) and a != -1) {
            auto it = m.upper_bound(a);
            if (it == m.end()) { m.insert(std::make_pair(a, 1)); }
            else {
                auto it2 = it;
                if (it2 != m.begin() and (--it2)->first == a)
                    --it;
                int cur_cnt = it->second+1;
                m[a] = cur_cnt;
                printf("[%d] = %d\n", a, cur_cnt);
                vmax = std::max(vmax, cur_cnt);
            }
        }
        if (posCase != 1) printf("\n");
        printf("Test #%d:\n", posCase++);
        printf("  maximum possible interceptions: %d\n", vmax);
    }
    return 0;
}
