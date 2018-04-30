#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

#include "solve1.h"

int main() {
    int N, T, x;
    std::cin >> N >> T;

    std::vector<int> v;
    while (N--) {
        std::cin >> x;
        v.push_back(x);
    }

    Solution s;
    std::vector<int> ans = s.twoSum(v, T);
    for (int x : ans) {
        std::cout << x << " ";
    }

    return 0;
}
