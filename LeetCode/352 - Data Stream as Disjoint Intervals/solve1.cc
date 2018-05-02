#include <iostream>
#include <vector>
#include <map>

using std::vector;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

#include "solve1.h"

int main() {

    SummaryRanges obj;

    int val;
    while (std::cin >> val) {
        obj.addNum(val);
        vector<Interval> param_2 = obj.getIntervals();
        for (const auto & x : param_2) {
            std::cout << "[" << x.start << "," << x.end << "]" << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
