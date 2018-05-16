int solution(int A, int B, int K) {
    if (A%K != 0) {
        A += (K-A%K);
    }
    return (B >= A) ? ((B-A)/K+1) : 0;
}
