#include <iostream>
#include <set>
#include <vector>

using std::vector;
#include "solve1.h"

int main() {
    std::vector<std::vector<int> > rectangles;

    int x1, y1, x2, y2;
    while (std::cin >> x1 >> y1 >> x2 >> y2) {
        std::vector<int> v = {x1, y1, x2, y2};
        rectangles.push_back(v);
    }

    Solution s;
    std::cout << s.isRectangleCover(rectangles) << std::endl;

    return 0;
}
