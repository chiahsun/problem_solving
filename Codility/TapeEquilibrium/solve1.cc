// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    int sum1 = A[0], sum2 = 0;
    for (int i = 1; i < A.size(); ++i) sum2 += A[i];
    
    int min_diff = abs(sum1 - sum2);
    for (int i = 1; i < A.size()-1; ++i) {
        int cur = A[i];
        sum1 += cur;
        sum2 -= cur;
        min_diff = std::min(min_diff, abs(sum1 - sum2));
    }
    
    return min_diff;
}
