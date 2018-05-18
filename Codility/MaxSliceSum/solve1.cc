int solution(vector<int> &A) {
    int N = A.size();
    int L[N], R[N];
    L[0] = A[0], R[N-1] = A[N-1];

    int ans = A[0];
    for (int i = 1; i < A.size(); ++i) {
        ans = std::max(ans, A[i]);
        L[i] = std::max(L[i-1], 0) + A[i];
        R[N-i-1] = std::max(R[N-i], 0) + A[N-i-1];
    }
    
    for (int i = 0; i < A.size()-1; ++i) {
        ans = std::max(ans, L[i]+R[i+1]);
    }
    return ans;
}
