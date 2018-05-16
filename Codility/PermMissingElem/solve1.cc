// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    long long sum = 0, N = A.size();
    for (int x : A) sum += x;
    return (N+2)*(N+1)/2 - sum;
}
