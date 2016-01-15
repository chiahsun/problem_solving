#include <cstdio>
#include <vector>

std::vector<std::pair<int, int> > v;

int main() {
    int k;
    while (scanf("%d", &k) == 1) {
        v.clear();
        for (int y = k+1; y <= 2*k; ++y) {
            int nu = k * y;
            int de = y - k;
            if (nu % de == 0) {
                v.push_back(std::make_pair(nu/de, y));
            }
        }
        printf("%lu\n", v.size());
        for (const auto & pr : v) {
            printf("1/%d = 1/%d + 1/%d\n", k, pr.first, pr.second);
        }
    }
    return 0;
}
