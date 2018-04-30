class Solution {
public:
    int kthSmallest(vector<vector<int> >& matrix, int k) {
        
        const int N = matrix.size();
        const int nLarger = N*N - k;
        int lo = matrix[0][0], hi = matrix[N-1][N-1];
        
        while (lo != hi) {
            int mid = lo + (hi-lo)/2;
            
            int curNumLarger = 0;
            for (int i = 0; i < N; ++i) {
                int nLarger = (matrix[i].end() - std::upper_bound(matrix[i].begin(), matrix[i].end(), mid));
                curNumLarger += nLarger;;
            }
            
            if (curNumLarger > nLarger) {
                lo = mid+1;
            } else if (curNumLarger <= nLarger) {
                hi = mid;
            }
        }
        
        return lo;
    }
};

