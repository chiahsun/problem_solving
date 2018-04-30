#include <iostream>
#include <vector>

using std::vector;

#include "solve2.h"

int main() {
    int N, K;
    std::cin >> N;

    std::vector<std::vector<int> > v;
    for (int i = 0; i < N; ++i) {
        std::vector<int> v2;
        for (int k = 0, x; k < N; ++k) {
            std::cin >> x;
            v2.push_back(x);
        }
        v.push_back(v2);
    }

    std::cin >> K;
    Solution s;
    std::cout << s.kthSmallest(v, K) << std::endl;

    return 0;
}
