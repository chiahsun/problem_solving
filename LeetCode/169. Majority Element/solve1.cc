class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int prev = nums[0], i = 1, cnt = 1; i < nums.size(); ++i) {
            if (nums[i] == prev) { ++cnt; }
            else                 { prev = nums[i]; cnt = 1; }
            if (cnt > nums.size() / 2)
                return prev;
        }
        return nums[0];
    }
};
