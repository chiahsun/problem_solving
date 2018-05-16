#include <algorithm>

int solution(vector<int> &A) {
    int N = A.size();
    std::sort(A.begin(), A.end());
    int offset = A.size();
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] >= 0) {
            offset = i;
            break;
        }
    }
    int max_product = A[N-3]*A[N-2]*A[N-1]; // all n
    // 3p
    if (offset+2 < A.size()) {
        max_product = std::max(max_product, A[N-3]*A[N-2]*A[N-1]);
    }
    // 1p2n
    if (offset < A.size() && offset >= 2) {
        max_product = std::max(max_product, A[offset-1]*A[offset-2]*A[N-1]);
    }
    
    return max_product;
}
