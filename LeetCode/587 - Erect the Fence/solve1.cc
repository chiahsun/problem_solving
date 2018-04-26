#include <iostream>
#include <vector>

// const static bool debug = false;
const static bool debug = true;

struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};

using std::vector;
#include "solve1.h"

int main() {
    int N;
    std::cin >> N;

    std::vector<Point> points;
    for (int i = 0, x, y; i < N; ++i) {
        std::cin >> x >> y;
        points.push_back(Point(x, y));
    }

    Solution s;
    std::vector<Point> ans = s.outerTrees(points);
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i].x << " " << ans[i].y << std::endl;
    }

    return 0;
}
