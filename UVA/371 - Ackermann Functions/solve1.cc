#include <algorithm>

const int M = 64;
long long power_of_2[M];
int len_of_power_of_2[M];

const long long NUM = 1000000;
int f[NUM] = {0};

int compute(long long x) {
    if (x == 1) return 3;
    if (x < NUM and f[x]) return f[x];
    int val = 1;
    // power of 2
    if ((x & (x-1)) == 0) {
        auto it = std::lower_bound(power_of_2, power_of_2+M, x);
        val = len_of_power_of_2[it-power_of_2];
    } else {
        val = 1 + compute((x % 2 == 0) ? x/2 : 3*x+1);
    }
    if (x < NUM) f[x] = val;
    return val;
}

void compute_table() {
    long long now = 1;
//    power_of_2[0] = 1;
//    len_of_power_of_2[0] = 1;
    for (int i = 0; i < M; ++i, now <<= 1) {
        power_of_2[i] = now;
        len_of_power_of_2[i] = i;
    }
}

int main() {
    compute_table();
    long long lo, hi;
    while (scanf("%lld%lld", &lo, &hi) == 2) {
        if (lo == 0 and hi == 0) break;
        if (lo > hi) std::swap(lo, hi);
        int longest_len = 0;
        long long longest_key = 0;
        for (long long i = lo; i <= hi; ++i) {
            int len = compute(i);
            if (len > longest_len) {
                longest_len = len;
                longest_key = i;
            }
        }

        printf("Between %lld and %lld, %lld generates the longest sequence of %d values.\n", lo, hi, longest_key, longest_len);
    }

    return 0;
}
