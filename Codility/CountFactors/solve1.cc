int solution(int N) {
    int i = 1, ans = 0;
    while (i*i < N) {
        if (N % i == 0) ans += 2;
        ++i;
    }
    if (i*i == N) ++ans;
    return ans;
}
