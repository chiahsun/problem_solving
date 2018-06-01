#include <numeric>

bool check(int target_large_sum, int K, const std::vector<int> & A) {

    int sum = 0, used_block = 1;
    for (int i = 0; i < A.size(); ++i) {
        if (sum + A[i] > target_large_sum) {
            sum = A[i];
            ++used_block;
            if (used_block > K) {
                return false;
            }
        } else {
            sum += A[i];
        }
    }
    return true;
}

int solution(int K, int M, vector<int> &A) {
    
    int min = 0, max = 0;
    for (int i = 0; i < A.size(); ++i) {
        int cur = A[i];
        min = std::max(min, cur);
        max += cur;
    }
    
    int ans = max;
    while (min <= max) {
        int mid = min + (max-min)/2;
        
        if (check(mid, K, A)) {
            ans = mid;
            max = mid-1;
        } else {
            min = mid+1;
        }
    }
    
    return ans;
}
