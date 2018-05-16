// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int to_val(char c) {
    switch(c) {
        case 'A': return 1;
        case 'C': return 2;
        case 'G': return 3;
        case 'T': return 4;
    }
    return 0;
}

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    int N = S.size();
    int L[4][N], R[4][N];
    int LP[4] = {-1, -1, -1, -1};
    for (int i = 0; i < N; ++i) {
        int val = to_val(S[i]);
        int index = val-1;
        LP[index] = i;
        for (int k = 0; k < 4; ++k) {
            L[k][i] = LP[k];
        }
    }
    int RP[4] = {N, N, N, N};
    for (int i = N-1; i >=0; --i) {
        int val = to_val(S[i]);
        int index = val-1;
        RP[index] = i;
        for (int k = 0; k < 4; ++k) {
            R[k][i] = RP[k];
        }
    }
    std::vector<int> ans;
    for (int i = 0; i < P.size(); ++i) {
        int from = P[i], to = Q[i];
        for (int k = 0; k < 4; ++k) {
            if (L[k][to] >= from && R[k][from] <= to) {
                ans.push_back(k+1);
                break;
            }
        }
    }
    
    return ans;
}
