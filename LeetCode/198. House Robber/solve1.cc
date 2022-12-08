class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return std::max(nums[0], nums[1]);
        int a[2] = {nums[0], nums[1]};
        int vmax = 0;
        for (int i = 2; i < nums.size(); ++i) {
            int cur[2] = {std::max(a[0], a[1]), a[0]+nums[i]};
            vmax = std::max(cur[0], cur[1]);
            a[0] = cur[0], a[1] = cur[1];
        }
        return vmax;
    }
};