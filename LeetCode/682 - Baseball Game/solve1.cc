#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
#include "solve1.h"

int main() {
    std::vector<std::string> v;
    std::string data[] = {"5", "2", "C", "D", "+"};
    for (int i = 0; i < sizeof(data)/sizeof(data[0]); ++i) {
        v.push_back(data[i]);
    }
    Solution s;
    std::cout << s.calPoints(v) << std::endl;
    return 0;
}
