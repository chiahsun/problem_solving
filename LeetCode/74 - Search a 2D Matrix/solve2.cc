class Solution {
public:
    bool searchMatrix(vector<vector<int> > & matrix, int target) {
        if (matrix.empty() || matrix.front().empty() || matrix.front().front() > target || matrix.back().back() < target)
            return false;
        const int M = matrix.size();
        const int N = matrix[0].size();
        int lo = 0, hi = M * N - 1;
        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            int value = matrix[mid/N][mid%N];
            if (value > target) hi = mid-1;
            else if (value < target) lo = mid+1;
            else return true;
        }
        
        return false;
    }
};

