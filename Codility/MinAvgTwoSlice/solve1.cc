int solution(vector<int> &A) {
    int min_sum_2 = A[0]+A[1], min_pos = 0, min_sum_3 = A[0] + A[1] + (A.size() > 2 ? A[2] : 0);
    
    for (int i = 1; i < A.size()-1; ++i) {
        int cur_sum_2 = A[i] + A[i+1];
        if (cur_sum_2 < min_sum_2) {
            min_sum_2 = cur_sum_2;
            min_pos = i;
        }
    }
    for (int i = 1; i < A.size()-2; ++i) {
        int cur_sum_3 = A[i] + A[i+1] + A[i+2];
        if (cur_sum_3 < min_sum_3) {
            if (cur_sum_3 * 2 < min_sum_2 * 3 || (cur_sum_3 * 2 == min_sum_2 * 3 && i < min_pos)) {
                min_pos = i;
                min_sum_3 = cur_sum_3;
            }
        }
    }
    return min_pos;
}
