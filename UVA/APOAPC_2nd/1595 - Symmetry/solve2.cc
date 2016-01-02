#include <cstdio>

#include <vector>
#include <utility>
#include <set>
#include <map>
#include <algorithm>

const int MAX = 10000 + 5;
const int MIN = -10000 - 5;

int main() {
    int nCase;
    scanf("%d", &nCase);


    while (nCase--) {
        int nDot;
        scanf("%d", &nDot);

        std::map<int, std::set<int> > mapDot;
        std::vector<std::pair<int, int> > vecDot;
        int min_x = MAX, max_x = MIN;

        while (nDot--) {
            int x, y;
            scanf("%d%d", &x, &y);
            mapDot[x].insert(y);
            vecDot.push_back(std::make_pair(x, y));
            min_x = std::min(min_x, x);
            max_x = std::max(max_x, x);
        }


        //    mid = (min_x + max_x) / 2;
        //    left + sum - x = right;
        const int sum = min_x + max_x;
        bool is_symmetry = true;
        for (const auto & dot : vecDot) {
            int x = dot.first;
            int y = dot.second;
            if (sum % 2 == 0) {
                if (x * 2 == sum)
                    continue;
            }
            int another = sum - x;
            if (!mapDot.count(another) or !mapDot[another].count(y)) {
                is_symmetry = false;
                break;
            }
        }

        printf("%s\n", is_symmetry ? "YES" : "NO");
    }


    return 0;
}
