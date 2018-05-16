#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

#include "solve1.h"


int main() {

    Solution s;
    // std::vector<int> v = {1, 2, 0};
    std::vector<int> v = {3, 4, -1, 1};
    std::cout << s.firstMissingPositive(v) << std::endl;

    return 0;
}
