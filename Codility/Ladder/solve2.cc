int fib(int x, std::vector<int> & results) {

    while (x >= results.size()) {
        int N = results.size();
        results.push_back((results[N-1] + results[N-2]) % (1<<30));
    }    
    
    return results[x];
}

vector<int> solution(vector<int> &A, vector<int> &B) {
    std::vector<int> ans, results{1, 1};
    for (int i = 0; i < A.size(); ++i) {
        ans.push_back(fib(A[i], results) % (1 << B[i]));
    }
    return ans;
}
