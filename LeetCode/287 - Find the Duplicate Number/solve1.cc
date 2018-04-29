class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 0, k = 1; ; ++i, ++k) {
            if (nums[k] == nums[i]) return nums[i];
        }
        return -1;
    }
};
