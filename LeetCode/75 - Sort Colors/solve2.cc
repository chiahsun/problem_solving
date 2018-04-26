#include <iostream>
#include <vector>

using std::vector;

#include "solve2.h"

int main() {
    int N, x;
    std::cin >> N;

    std::vector<int> v;
    while(N--) {
        std::cin >> x;
        v.push_back(x);
    }

    Solution s;
    s.sortColors(v);
    for (int val : v) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}

