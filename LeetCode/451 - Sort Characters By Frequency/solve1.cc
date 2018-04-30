#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using std::string;

#include "solve1.h"

int main() {

    std::string s;
    std::cin >> s;

    Solution sol;
    std::cout << sol.frequencySort(s) << std::endl;

    return 0;
}
