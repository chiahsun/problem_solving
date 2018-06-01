int solution(vector<int> &A) {

    int N = A.size();
    int pl = 0, pr = N-1;
    long long L = abs((long long)A[pl]), R = abs((long long)A[pr]);
    int ans = (L == R) ? 1 : 2;
    
    while (pl < pr) {
        if (L < R) {
            --pr;
            long long cur = abs((long long)A[pr]);
            if (cur != R) {
                if (cur != L) {
                    ++ans;
                    // std::cout << "Add for " << A[pr] << " L: " << L << " R: " << R << " ans: " << ans << std::endl;
                } else {
                    if (A[pl] == A[pr]) break;
                }
                R = cur;
            }
        } else {
            ++pl;
            long long cur = abs((long long)A[pl]);
            if (cur != L) {
                if (cur != R) {
                    ++ans;
                    // std::cout << "Add for " << A[pr] << " L: " << L << " R: " << R << " ans: " << ans << std::endl;
                } else {
                    if (A[pl] == A[pr]) break;
                }
                L = cur;
            }
        }
    }
    
    return ans;
}
