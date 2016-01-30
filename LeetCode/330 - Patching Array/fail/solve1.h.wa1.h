class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        std::vector<bool> sum(n+1, false);
        sum[0] = true;
        for (int i = 0; i < nums.size(); ++i) {
            int cur = nums[i];
            for (int k = sum.size()-1; k >= 0; --k) {
                if (sum[k] and k+cur < sum.size())
                     sum[k+cur] = true;
            }
        }
        int npatch = 0;
        for (int i = 1; i < sum.size(); ++i) {
            if (not sum[i]) {
                ++npatch;
                sum[i] = true;
                for (int k = sum.size()-1; k >= 0; --k)
                    if (sum[k] and (k+i) < sum.size())
                        sum[k+i] = true;
            }
        }
        return npatch;
    }
};
