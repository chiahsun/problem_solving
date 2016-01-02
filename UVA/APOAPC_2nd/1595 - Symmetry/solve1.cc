#include <cstdio>

#include <utility>
#include <set>
#include <algorithm>

const int MAX = 10000 + 5;
const int MIN = -10000 - 5;

int main() {
    int nCase;
    scanf("%d", &nCase);


    while (nCase--) {
        int nDot;
        scanf("%d", &nDot);

        std::set<std::pair<int, int> > dots;
        int min_x = MAX, max_x = MIN;

        while (nDot--) {
            int x, y;
            scanf("%d%d", &x, &y);
            dots.insert(std::make_pair(x, y));
            min_x = std::min(min_x, x);
            max_x = std::max(max_x, x);
        }


        //    mid = (min_x + max_x) / 2;
        //    left + sum - x = right;
        const int sum = min_x + max_x;
        bool is_symmetry = true;
        for (const auto & dot : dots) {
            int x = dot.first;
            int y = dot.second;
            if (sum % 2 == 0) {
                if (x * 2 == sum)
                    continue;
            }
            int another = sum - x;
            if (dots.count(std::make_pair(another, y)) == 0) {
                is_symmetry = false;
                break;
            }
        }

        printf("%s\n", is_symmetry ? "YES" : "NO");
    }


    return 0;
}
