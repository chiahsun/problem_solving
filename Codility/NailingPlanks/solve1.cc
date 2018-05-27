// #include <algorithm>

bool check(int mid, 
           std::vector<int> plankNailedCount, 
           std::vector<std::vector<int> > nailPlankPos) {
    for (int i = mid+1; i < nailPlankPos.size(); ++i) {
        for (int pos : nailPlankPos[i]) {
            --plankNailedCount[pos];
            if (plankNailedCount[pos] == 0)
                return false;
        }
    }
    return true;
}

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    std::vector<int> plankNailedCount(A.size(), 0);
    std::vector<std::vector<int> > nailPlankPos(C.size(), std::vector<int>());
    
    int nAbleNailed = 0;
    for (int c_pos = 0; c_pos < C.size(); ++c_pos) {
        int c = C[c_pos];
        for (int i = 0; i < A.size(); ++i) {
            int begin = A[i], end = B[i];
            if (begin <= c && c <= end) {
                if (plankNailedCount[i] == 0) ++nAbleNailed;
                ++plankNailedCount[i];
                nailPlankPos[c_pos].push_back(i);
            }
        }
    }
    if (nAbleNailed < A.size()) {
        return -1;
    }
    
    int begin = 0, end = A.size()-1, mid = 0, ans = 0;
    while (begin <= end) {
        mid = begin + (end-begin)/2;
        if (check(mid, plankNailedCount, nailPlankPos)) {
            ans = mid;
            end = mid-1;
        } else {
            begin = mid+1;
        }
    }
    
    return ans+1;
}
