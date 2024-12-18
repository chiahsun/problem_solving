#include <ctime>
#include <iostream>
#include <vector>

using std::vector;
#include "solve2.h"

int main() {
    int N, K, x;
    std::cin >> N >> K;

    std::vector<int> v;
    while (N--) {
        std::cin >> x;
        v.push_back(x);
    }

    Solution s;
    std::cout << "Start solve " << std::endl;
    std::cout << s.findKthLargest(v, K) << std::endl;

    return 0;
}
