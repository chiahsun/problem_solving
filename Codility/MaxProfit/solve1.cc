int solution(vector<int> &A) {
    if (A.empty()) return 0;
    int max_profit = 0;
    int min_value = A[0];
    for (int i = 1; i < A.size(); ++i) {
        int cur_value = A[i];
        if (cur_value < min_value) min_value = cur_value;
        else {
            max_profit = std::max(max_profit, cur_value - min_value);
        }
    }
    return max_profit;
}
