class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0};
        for (int val : nums) {
            ++count[val];
        }
        for (int i = 0, k = 0; k < 3; ++k) {
            while (count[k]--) nums[i++] = k;
        }   
    }
};
