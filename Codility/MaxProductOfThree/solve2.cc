#include <algorithm>
int solution(vector<int> &A) {
    int N = A.size();
    std::sort(A.begin(), A.end());
    // 3p, 3n
    int max_product = A[N-1]*A[N-2]*A[N-3];
    // 1p2n 
    max_product = std::max(max_product, A[N-1]*A[0]*A[1]);
    return max_product;
}
