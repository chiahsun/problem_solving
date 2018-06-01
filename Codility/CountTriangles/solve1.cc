#include <algorithm>

int solution(vector<int> &A) {
    if (A.size() < 3) return 0;
    
    int ans = 0;
    std::sort(A.begin(), A.end());
    
    for (int i = 0; i < A.size()-2; ++i) {
        int a = A[i];
        int pos = i+1;
        for (int k = i+1; k < A.size()-1; ++k) {
            int b = A[k];
            while (pos+1 < A.size() && (a + b > A[pos+1])) {
                ++pos;
                // std::cout << "a: " << a << " b: " << b << " A[" << (pos+1) << "] : " << A[pos] << std::endl;
            }
            // std::cout << "a: " << a << " b: " << b << " c: " << A[pos] << " pos-k: " << (pos-k) << std::endl << std::endl;
            ans += (pos - k);
        }
    }
    return ans;
}
