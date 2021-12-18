class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                if (pos != i)
                    nums[pos] = nums[i];
                ++pos;
            }
        }
        for (int i = pos; i < nums.size(); ++i)
            nums[i] = 0;
    }
};
