int solution(int N) {
    int a = 1;
    for (int i = 2; i*i <= N; ++i) {
        if (N % i == 0) a = i;
    }
    return 2 * (a + (N/a));
}
