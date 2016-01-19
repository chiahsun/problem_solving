#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <algorithm>

const bool debug = false;

bool double_equal(double d1, double d2) {
    return fabs(d1 - d2) < 1E-9;
}

long long solve(long long N, long long S1, long long V1, long long S2, long long V2) {
    double per_value_s1 = double(V1)/S1;
    double per_value_s2 = double(V2)/S2;
    // XXX: if equal value put large to s2
    if (per_value_s1 > per_value_s2 or (double_equal(per_value_s1, per_value_s2) and S1 > S2)) {
        std::swap(per_value_s1, per_value_s2);
        std::swap(S1, S2);
        std::swap(V1, V2);
    } 

    if (debug) {
        printf("N : %lld (S1, V1) : (%lld, %lld) (S2, V2) : (%lld, %lld)\n", N, S1, V1, S2, V2);
        printf("per value s1 : %f, per value s2 : %f\n", per_value_s1, per_value_s2);
    }

    long long max_num_s2 = N/S2;
    double per_waste = per_value_s2 - per_value_s1;
    long long left_num = N - max_num_s2 * S2;
    long long min_num_s1 = left_num / S1;
    long long left_left_num = left_num - min_num_s1 * S1;
    double max_regain = left_left_num * per_value_s1; 
    long long max_value = max_num_s2 * V2 + min_num_s1 * V1;
    if (max_regain == 0)
        return max_value;
    if (debug)
        printf("init ns1(%lld) ns2(%lld) max_value(%lld)\n", min_num_s1, max_num_s2, max_value);
    for (long long i = max_num_s2-1; i >= 0; --i) {
        double waste = (max_num_s2 - i) * S2 * per_waste;
        long long  k = (N - i * S2)/S1;
        long long value = i * V2 + k * V1;
        max_value = std::max(max_value, value);
        if (debug)
            printf("ns1(%lld) ns2(%lld) value(%lld) max_value(%lld) waste(%f) max_regain(%f)\n", k, i, value, max_value, waste, max_regain);
        if (waste > max_regain) {
//            if (debug)
                printf("break at waste(%f) > max_regain(%f)\n", waste, max_regain);
            break;
        }
        if (k > 0 and (k * S1) % S2 == 0) {
//            if (debug)
                printf("break at (ns1 * s1) %% s2 == 0, (%lld * %lld) %% %lld == \n", k, S1, S2);
            break;
        }
    }

    return max_value;
}

int main() {
    int nCase, posCase = 1;
    scanf("%d", &nCase);
    int N, S1, V1, S2, V2;
    while (nCase--) {
        scanf("%d%d%d%d%d", &N, &S1, &V1, &S2, &V2);
        printf("Case #%d: %lld\n", posCase++, solve(N, S1, V1, S2, V2));
    }
    return 0;
}
