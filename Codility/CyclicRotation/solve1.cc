// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, int K) {
    int N = A.size();
    
    vector<int> B = A;
    for (int i = 0; i < A.size(); ++i) {
        A[i] = B[((i-K) % N + N)%N];
    }
    
    return A;
}
