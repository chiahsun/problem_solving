#include <cmath>

int get_factor(int N, int prime) {
    if (N % prime != 0) return 1;
    
    int cnt = 1;
    int product = prime;
    while (N >= product && (N % product == 0)) {
        ++cnt;
        if (2147483647 / prime >= product) 
            product *= prime;
        else
            break;
    }
    return cnt;
}

int solution(int N) {
    const int M = sqrt(N)+1;
    int S[N+1];
    S[2] = true;
    for (int i = 3; i < N+1; i += 2) S[i] = true;
    int ans = 1;
    ans *= get_factor(N, 2);
    for (int i = 3; i < N+1; i += 2) {

        if (S[i]) {
            for (int k = i+i; k < N+1; k+=i) {
                S[k] = false;
            }
            
            ans *= get_factor(N, i);
        }
    }

    return ans;
}
