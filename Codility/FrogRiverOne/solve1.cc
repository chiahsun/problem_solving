// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, vector<int> &A) {
    if (A.size() < X) return -1;
    
    bool rock[X+1];
    for (int i = 0; i < sizeof(rock)/sizeof(rock[0]); ++i) {
        rock[i] = false;
    }
    int cnt = 0;
    for (int i = 0; i < A.size(); ++i) {
        int a = A[i];
        if (!rock[a]) {
            rock[a] = true;
            ++cnt;
        }
        if (cnt == X) return i;
    }
    return -1;
}
