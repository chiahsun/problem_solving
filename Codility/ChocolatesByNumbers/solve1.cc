int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int solution(int N, int M) {
    return N/gcd(N, M);
}
