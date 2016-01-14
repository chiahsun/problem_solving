#include <cstdio>
#include <algorithm>

int gain, loss;

int val[12];

int solve(int cur) {
    if (cur > 4) {
        int total = 0;
        for (int i = cur-5; i < cur; ++i) {
            total += val[i];
        }
        if (total >= 0)
            return -1;
    }
    if (cur == 12) {
        int sum = 0;
        for (int i = 0; i < 12; ++i)
            sum += val[i];
        return sum;
    }
    val[cur] = gain;
    int sum1 = solve(cur+1);
    val[cur] = -loss;
    int sum2 = solve(cur+1);
    return std::max(sum1, sum2);
}

int main() {
    while (scanf("%d%d", &gain, &loss) == 2) {
        int sum = solve(0);
        if (sum >= 0)
            printf("%d\n", sum);
        else
            printf("Deficit\n");
    }
    return 0;
}
