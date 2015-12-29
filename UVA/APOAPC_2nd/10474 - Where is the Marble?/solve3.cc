#include <cstdio>
#include <vector>
#include <algorithm>


int main() {
    int nMarble, nQuery;
    std::vector<int> vec;

    int posCase = 1;
    while (scanf("%d%d", &nMarble, &nQuery) == 2 and not (nMarble == 0 and nQuery == 0)) {
        vec.clear();
        while (nMarble--) { int x; scanf("%d", &x); vec.push_back(x); }
        std::sort(vec.begin(), vec.end());

        printf("CASE# %d:\n", posCase++);

        while (nQuery--) {
            int query;
            scanf("%d", &query);

            std::vector<int>::iterator plow = std::lower_bound(vec.begin(), vec.end(), query);
            if (*plow == query)  
                printf("%d found at %ld\n", query, plow-vec.begin()+1);
            else
                printf("%d not found\n", query);
        }
    }
    return 0;
}
