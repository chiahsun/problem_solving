#include <iostream>
#include <vector>
#include <utility>

using std::vector;

#include "solve1.h"

int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int> > m;
    for (int i = 0, x; i < N; ++i) {
        std::vector<int> v;
        for (int k = 0; k < N; ++k) {
            std::cin >> x;
            v.push_back(x);
        }
        m.push_back(v);
    }

    Solution s;
    std::cout << s.swimInWater(m) << std::endl;

    return 0;
}
