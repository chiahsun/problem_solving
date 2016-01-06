class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] != cur) {
                if (cnt == 0) { cur = nums[i]; cnt = 1; }
                else          { --cnt; }
            } else {
                ++cnt;
            }
        return cur;
    }
};
