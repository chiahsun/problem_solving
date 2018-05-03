#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;

#include "solve1.h"

int main() {

    std::string line;
    std::vector<std::string> v;
    while (std::getline(std::cin, line)) {
        v.push_back(line);
        std::cout << "Add line: " << line << std::endl;
    }

    Solution s;
    std::vector<std::vector<std::string> > ans = s.findDuplicate(v);
    for (const auto & v : ans) {
        for (const auto & s : v) {
            std::cout << s << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
