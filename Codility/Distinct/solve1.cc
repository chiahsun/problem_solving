#include <algorithm>

int solution(vector<int> &A) {
    std::sort(A.begin(), A.end());
    int ans = (A.empty() ? 0 : 1), last = (A.empty() ? 0 : A[0]);
    for (int i = 1; i < A.size(); ++i) {
        if (A[i] != last) {
            ++ans;
            last = A[i];
        }
    }
    return ans;
}
