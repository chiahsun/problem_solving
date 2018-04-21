class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int v[grid[0].size()] = {0}; // top/bottom
        int h[grid.size()] = {0}; // left/right
        for (int i = 0; i < grid.size(); ++i) {
            for (int k = 0; k < grid[i].size(); ++k) {
                v[k] = std::max(v[k], grid[i][k]);
                h[i] = std::max(h[i], grid[i][k]);
            }
        }
        
        int sum = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int k = 0; k < grid[i].size(); ++k) {
                sum += (std::min(h[i], v[k]) - grid[i][k]);
            }
        }
        return sum;
    }
};
