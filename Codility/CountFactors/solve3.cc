#include <cmath>

int solution(int N) {
    int ans = 1, a = N;
    for (int i = 2; i*i <= N && a > 1; ++i) {
        int cnt = 1;
        while (a % i == 0) { ++cnt; a /= i; }
        ans *= cnt;
        // std::cout << "Count " << cnt << " for prime " << i << " ans: " << ans << std::endl;
    }
    if (a > 1) ans *= 2;
    return ans;
}
