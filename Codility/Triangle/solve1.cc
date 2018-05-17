#include <algorithm>

int solution(vector<int> &A) {
    if (A.size() < 3) return 0;
    int N = A.size();
    
    std::sort(A.begin(), A.end());

    for (int i = 0; i < N-2; ++i) {
        long a = A[i];
        long b = A[i+1];
        long c = A[i+2];
        if (a + b > c) {
            return 1;
        }
    }
    return 0;
}
