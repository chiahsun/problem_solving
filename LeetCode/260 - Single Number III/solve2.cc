class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        std::vector<int> v;
        for (int i = 0; i < nums.size(); ++i) {
            if (i+1 < nums.size() and nums[i+1] == nums[i])
                i += 1;
            else
                v.push_back(nums[i]);
        }
        
        return v;
    }
};
