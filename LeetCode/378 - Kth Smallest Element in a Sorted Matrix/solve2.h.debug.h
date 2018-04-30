class Solution {
public:
    int kthSmallest(vector<vector<int> >& matrix, int k) {
        
        const int N = matrix.size();
        const int nLarger = N*N - k;
        std::cout << "nLarger " << nLarger << " N " << N << " k " << k << std::endl; 
        int lo = matrix[0][0], hi = matrix[N-1][N-1];
        
        while (lo != hi) {
            int mid = lo + (hi-lo)/2;
            std::cout << "lo " << lo << " hi " << hi << " mid " << mid << std::endl;
            
            int curNumLarger = 0;
            for (int i = 0; i < N; ++i) {
                int nLarger = (matrix[i].end() - std::upper_bound(matrix[i].begin(), matrix[i].end(), mid));
                curNumLarger += nLarger;;
                std::cout << "    iteration " << i << " num larger " << nLarger << std::endl;
            }
           
            std::cout << " curNumLarger " << curNumLarger << std::endl; 
            if (curNumLarger > nLarger) {
                lo = mid+1;
            } else if (curNumLarger <= nLarger) {
                hi = mid;
            } 
        }
        
        return lo;
    }
};
