#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
    int nCase, N, x;
    scanf("%d", &nCase);
    while (nCase--) {
        std::vector<int> lis;
        scanf("%d", &N);
        while (N--) {
            scanf("%d", &x);

            auto it = std::lower_bound(lis.begin(), lis.end(), x);
            if (it == lis.end())
                lis.push_back(x);
            else if (*it != x)
                *it = x;
        }

        printf("%lu\n", lis.size());
    }
    return 0;
}
