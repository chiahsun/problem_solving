#include <cstdio>
#include <vector>
#include <algorithm>


std::vector<int> A, dp, prev;

void print_prev(int pos) {
    if (pos != prev[pos]) {
        print_prev(prev[pos]);
    }
    printf("%d\n", A[pos]);
}

int main() {
    int x;
    
    while (scanf("%d", &x) == 1) 
        A.push_back(x);
    dp.resize(A.size());
    prev.resize(A.size());

    int max_pos = 0, max_size = 0;
    for (size_t i = 0; i < A.size(); ++i) {
        dp[i] = 1;
        prev[i] = i;

        for (int k = i-1; k >= 0; --k) {
            if (A[i] > A[k]) {
                if (dp[k]+1 > dp[i]) {
                    dp[i] = dp[k]+1;
                    prev[i] = k;
                }
            }
        }

        if (dp[i] >= max_size) {
            max_size = dp[i];
            max_pos = i;
        }
    }


    printf("%d\n-\n", max_size);
    print_prev(max_pos);
    return 0;
}
