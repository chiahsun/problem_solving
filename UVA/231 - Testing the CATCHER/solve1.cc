#include <cstdio>
#include <vector>
#include <algorithm>

struct GreaterCompare {
    bool operator () (int a, int b) const
      { return a > b; }
};

int main() {
    int posCase = 1, a;
    while (scanf("%d", &a) and a != -1) {
        std::vector<int> len_to_max_height;
        len_to_max_height.push_back(0); // dummy len of 0
        len_to_max_height.push_back(a);
        int prev_len = 1, prev_height = a;
        while (scanf("%d", & a) and a != -1) {
            auto it = std::upper_bound(len_to_max_height.begin()+1, len_to_max_height.end(), a, GreaterCompare());
            if (!GreaterCompare() (a, *it))
                prev_len = len_to_max_height.size();
            else
                prev_len = it - len_to_max_height.begin();
             
            prev_height = a;
            if (prev_len >= len_to_max_height.size())
                len_to_max_height.push_back(prev_height);
            else if (len_to_max_height[prev_len] < prev_height)
                len_to_max_height[prev_len] = prev_height;
#if 0
            printf("\nlen    : ");
            for (int i = 1; i < len_to_max_height.size(); ++i) 
                printf("%4d", i);
            printf("\nheight : ");
            for (int i = 1; i < len_to_max_height.size(); ++i) 
                printf("%4d", len_to_max_height[i]);
            printf("\n");
#endif
        }
        if (posCase != 1) printf("\n");
        printf("Test #%d:\n", posCase++);
        printf("  maximum possible interceptions: %lu\n", len_to_max_height.size()-1);
    }
    return 0;
}
