int solution(vector<int> &A) {
    int nwest = 0, count = 0;
    for (int i = A.size()-1; i >= 0; --i) {
        if (A[i]) ++nwest;
        else count += nwest;
        if (count > 1000000000) return -1;
    }
    
    return count;
}
