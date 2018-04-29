#include <iostream>
#include <vector>

using std::vector;
#include "solve3.h"

int main() {
    int N, x;
    std::cin >> N;

    std::vector<int> v;
    while (N--) {
        std::cin >> x;
        v.push_back(x);
    }
    Solution s;
    std::cout << s.arrayPairSum(v) << std::endl;

    return 0;
}
