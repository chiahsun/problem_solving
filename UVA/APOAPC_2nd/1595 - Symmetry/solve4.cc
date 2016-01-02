#include <cstdio>

#include <utility>
#include <vector>
#include <algorithm>

const int MAX = 10000 + 5;
const int MIN = -10000 - 5;

struct Compare {
    bool operator () (const std::pair<int, int> & lhs, const std::pair<int, int> & rhs) {
        if (lhs.first != rhs.first)
            return lhs.first < rhs.first;
        return lhs.second < rhs.second;
    }
};

struct SecondCompare {
    bool operator () (const std::pair<int, int> & lhs, const std::pair<int, int> & rhs) {
        if (lhs.first != rhs.first)
            return lhs.first < rhs.first;
        return lhs.second > rhs.second;
    }
};

int main() {
    int nCase;
    scanf("%d", &nCase);


    while (nCase--) {
        int nDot;
        scanf("%d", &nDot);

        std::vector<std::pair<int, int> > dots;
        int min_x = MAX, max_x = MIN;

        while (nDot--) {
            int x, y;
            scanf("%d%d", &x, &y);
            dots.push_back(std::make_pair(x, y));
            min_x = std::min(min_x, x);
            max_x = std::max(max_x, x);
        }

        std::sort(dots.begin(), dots.end(), Compare());
        const int sz = dots.size();

        std::sort(dots.begin() + sz/2 + (sz % 2), dots.end(), SecondCompare());
#if 0
        for (auto & x : dots) {
            printf("(%d, %d) ", x.first, x.second);
        }
        printf("\n");
#endif
        
        const int sum = min_x + max_x;
        bool is_symmetry = true;
        for (int i = 0; i < sz/2 + (sz % 2) ? 1 : 0; ++i) {
            int x = dots[i].first;
            int y = dots[i].second;
            
            if (x * 2 == sum)
                continue;
            if (x + dots[sz-i-1].first != sum or y != dots[sz-i-1].second) {
                is_symmetry = false;
                break;
            }
        }


        printf("%s\n", is_symmetry ? "YES" : "NO");
    }


    return 0;
}
