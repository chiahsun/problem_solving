class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int offset = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= 0) {
                std::swap(nums[i], nums[offset]);
                ++offset;
            }
        }
        
        for (int i = offset; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1 + offset;
            if (index < nums.size()) {
                if (nums[index] > 0) {
                    nums[index] = -nums[index];
                }
            }
        }

        for (int i = offset; i < nums.size(); ++i) {
            if (nums[i] > 0) return i-offset+1;
        }
  
        return nums.size() - offset + 1;
    }
};

