int fib(int x, int mod) {
    int a = 0, b = 1;
    while (x--) {
        int tmp = b;
        b = (a+b) % mod;
        a = tmp;
    }
    
    return b;
}

vector<int> solution(vector<int> &A, vector<int> &B) {
    std::vector<int> ans;
    for (int i = 0; i < A.size(); ++i) {
        ans.push_back(fib(A[i], 1 << B[i]));
    }
    return ans;
}
