bool find_major_element(const std::vector<int> & A, int & major, int & major_count) {
    if (A.empty()) return false;
    int count = 0, last = 0;
    for (int a : A) {
        if (count == 0) {
            last = a;
            count = 1;
        } else {
            if (a == last) ++count;
            else           --count;
        }
    }
    count = 0;
    for (int a : A) {
        if (a == last) ++count;
    }
    if (count > A.size()/2) {
        major = last;
        major_count = count;
        return true;
    }
    return false;
}

int solution(vector<int> &A) {
    int N = A.size();
    int major, major_count;
    bool ok = find_major_element(A, major, major_count);
    if (!ok) return 0;
    
    int count_first = 0, count_second = major_count, ans = 0;
    for (int i = 0; i < A.size()-1; ++i) {
        int cur = A[i];
        if (cur == major) {
            ++count_first;
            --count_second;
        }
        if (count_first > (i+1)/2 && (count_second > (N-i-1)/2)) {
            ++ans;
        }
    }
    return ans;
}
