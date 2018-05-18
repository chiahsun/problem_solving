int solution(vector<int> &A) {
    int min_val = A[1], max_prefix_sum = 0, ans = 0;

    for (int i = 2; i < A.size()-1; ++i) {
        int cur = A[i];
        
        if (max_prefix_sum >= 0) {
            if (cur < min_val) {
                max_prefix_sum = max_prefix_sum + min_val;
                min_val = cur;
            } else {
                max_prefix_sum += cur;  
            }
        } else {
            min_val = cur;
            max_prefix_sum = 0;
        }
        ans = std::max(ans, max_prefix_sum);
    }
    return ans;
}
