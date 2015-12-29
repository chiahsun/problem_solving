#include <cstdio>

#include <iostream>
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

            int pos_begin = 0, pos_end = vec.size()-1;
            int pos_mid = 0;
            while (query >= vec[pos_begin] and query <= vec[pos_end] and pos_begin <= pos_end) {
                pos_mid = (pos_begin + pos_end)/2;
                int mid = vec[pos_mid];
                if (mid == query) {
                    break;
                } else if (mid > query) {
                    pos_end = pos_mid-1;
                } else {
                    pos_begin = pos_mid+1;  
                }
            }
            if (vec[pos_mid] == query) {
                while (pos_mid-1 >= 0 and vec[pos_mid-1] == query) {
                    --pos_mid;
                }
                printf("%d found at %d\n", query, pos_mid+1);
            } else {
                printf("%d not found\n", query);
            }
        }
    }
    return 0;
}
