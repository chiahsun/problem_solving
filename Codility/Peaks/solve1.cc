bool each_block_has_one_peak(const std::vector<int> peak_indices, int group_size, int N) {
    // for (int p : peak_indices) std::cout << p << " ";
    // std::cout << std::endl;
    for (int i = 0, peak_pos = 0; i < N; i += group_size) {
        bool ok = false;
        int end = i+group_size; //[begin, end)
        while (peak_pos < peak_indices.size()) {
            int cur = peak_indices[peak_pos];
            if (cur < end) {
                ok = true;
                ++peak_pos;
            } else {
                break;
            }
        }
        if (!ok) return false;
    }
    
    return true;
}

int solution(vector<int> &A) {
    const int N = A.size();
    
    std::vector<int> peak_indices;
    for (int i = 1; i < N-1; ++i) {
        if (A[i] > A[i-1] && A[i] > A[i+1]) peak_indices.push_back(i);
    }
    if (peak_indices.empty()) return 0;
    
    const int peak_size = peak_indices.size();
    // std::cout << "peak size: " << peak_size << std::endl;

    int backup_ans = 0;
    int start_group_size = (N/peak_size + (N%peak_size == 0 ? 0 : 1));
    // std::cout << "Start group size: " << start_group_size << std::endl;
    // Should check sqrt() for save iteration time?
    for (int i = start_group_size; i <= N; ++i) {
        // std::cout << "Before check N " << i << " " << N << std::endl;
        if (N % i == 0) {
            // std::cout << "Check N " << std::endl;
            if (each_block_has_one_peak(peak_indices, i, N)) {
                return N/i;
            }
            /*int k = N/i;
            if (i != k && each_block_has_one_peak(peak_indices, k, N)) {
                backup_ans = i;
            }*/
        }
    }
    return backup_ans;
}
