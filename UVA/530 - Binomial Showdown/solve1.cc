#include <cstdio>
#include <utility>
#include <map>

std::map<std::pair<int, int>, int> mapBinomial;

int get_binomial(int n, int k) {
    if (k == 0) return 1;
    if (k == 1) return n;
    if (k > n-k) return get_binomial(n, n-k);
    if (mapBinomial.count(std::make_pair(n, k))) return mapBinomial[std::make_pair(n, k)];

    return mapBinomial[std::make_pair(n, k)] = (get_binomial(n-1, k) + get_binomial(n-1, k-1));
}

int main() {
    int N, K;
    while (scanf("%d%d", &N, &K) == 2 and N) {
        printf("%d\n", get_binomial(N, K));
    }
    return 0;
}
