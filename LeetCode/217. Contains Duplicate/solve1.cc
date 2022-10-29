class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i+1 < nums.size(); ++i) {
            if (nums[i] == nums[i+1])
                return true;
        }
        return false;
    }
};
