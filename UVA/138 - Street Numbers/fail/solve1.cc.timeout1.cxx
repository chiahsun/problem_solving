#include <cstdio>

unsigned long long sum(unsigned long long from, unsigned long long to) { return (from+to) * (to-from+1) / 2; }

int main() {
    int cnt = 0;
    for (int i = 3; i<= 10E9; ++i) {
        int begin = 2, end = i-1;
        while (begin <= end) {
            int mid = begin+(end-begin)/2;
            // int mid = (begin+end)/2;
            // printf("[%d, %d, %d]\n", begin, mid, end);
            unsigned long long a = sum(1, mid-1);
            unsigned long long b = sum(mid+1, i);
            if (a == b) {
                printf("%10d%10d (%llu)\n", mid, i, a);
                ++cnt;
                break;
            } else if (a > b) {
                end = mid-1;
            } else {
                begin = mid+1;
            }
        }
        if (cnt == 10)
            break;
    }
    return 0;
}
