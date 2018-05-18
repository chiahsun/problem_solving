int solution(vector<int> &A) {
    int ans = A[0], max_prefix_sum = A[0];
    for (int i = 1; i < A.size(); ++i) {
        max_prefix_sum = std::max(max_prefix_sum, 0) + A[i];
        ans = std::max(ans, max_prefix_sum);
    }
    return ans;
}
