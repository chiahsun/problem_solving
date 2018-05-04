class Solution {
public:
    bool searchMatrix(vector<vector<int> > & matrix, int target) {
        if (matrix.empty() || matrix.front().empty() || matrix.front().front() > target || matrix.back().back() < target)
            return false;
        int lo = 0, hi = matrix.size()-1;
        if (matrix[hi][0] < target) {
            lo = hi;
        } else {
            while (lo <= hi) {
                int mid = lo + (hi-lo)/2;
                int value = matrix[mid][0];
                if (value > target) hi = mid-1;
                else if (value < target) lo = mid+1;
                else return true;
            }
        }
        if (matrix[lo][0] > target) --lo;
        
        auto it = std::lower_bound(matrix[lo].begin(), matrix[lo].end(), target);
        return (it != matrix[lo].end()) && (*it == target);
    }
};

