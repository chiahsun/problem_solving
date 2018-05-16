// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    int cnt = 0;
    for (int a : A) {
        int val = abs(a)-1;
        if (val >= A.size()) return 0;
        if (A[val] > 0) {
            A[val] = -A[val];
            ++cnt;
        } else {
            return 0;
        }
    }
    return cnt == A.size();
}
