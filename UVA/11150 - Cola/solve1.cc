#include <cstdio>

int main() {
    int N;
    while (scanf("%d", &N) == 1) {
        int total = N;
        while (N >= 3) {
            int left_bottles = N % 3;
            int new_bottles = (N - left_bottles)/3;
            total += new_bottles; 
            N = left_bottles + new_bottles;
        }
        if (N == 2) total += 1;
        printf("%d\n", total);
    }
    return 0;
}
