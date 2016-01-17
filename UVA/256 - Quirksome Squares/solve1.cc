#include <cstdio>
#include <vector>
#include <algorithm>

int ipow(int x, int e) {
    int res = 1;
    while (e--) res *= x;
    return res; 
}

void print_number(int x, int n_digit) {
    int s = ipow(10, n_digit);
    do {
        s /= 10;
        printf("%d", x/s%10);
    } while (s != 1);
    printf("\n");
}

int main() {
    int N;
    while (scanf("%d", &N) == 1) {
        std::vector<int> ans;
        N /= 2;
        int bound = ipow(10, N);
//        printf("bound : %d\n", bound);
        for (int i = 0; i < bound; ++i)
            for (int k = 0; k < bound; ++k) {
                int ans1 = (i * bound + k);
                if (ans1 == ipow(i + k, 2)) {
                    ans.push_back(ans1);
                }
                //    printf("%d%d\n", i, k);
            }

        std::sort(ans.begin(), ans.end());
        for (int x : ans) {
            print_number(x, N*2);
        }
    }
    return 0;
}
