vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    int M = N/2+1;
    bool s[M];
    std::vector<int> primes;
    for (int i = 0; i < M; ++i) s[i] = true;
    for (int i = 2; i < M; ++i) {
        if (s[i]) {
            primes.push_back(i);
            for (int k = i*i; k < M; k += i) s[k] = false;
        }
    }
    
    int count[N+1];
    for (int i = 0; i < N+1; ++i) count[i] = 0;
    
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= N; ++i) {
        for (int k = i; k < primes.size(); ++k) {
            int semiprime = primes[i] * primes[k];
            if (semiprime > N) break;
            count[semiprime] = 1;
        }
    }
 
    int total = 0;
    for (int i = 0; i < N+1; ++i) {
        if (count[i]) {
            total += 1;
        }
        count[i] = total;
    }
    std::vector<int> ans;
    for (int i = 0; i < P.size(); ++i) {
        ans.push_back(count[Q[i]] - count[P[i]-1]);
    }
    return ans;
}
