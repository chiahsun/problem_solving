class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto begin = std::lower_bound(nums.begin(), nums.end(), target);
        if (begin == nums.end() || *begin != target) return {-1, -1};
        
        auto end = std::upper_bound(nums.begin(), nums.end(), target);
        return {begin - nums.begin(), end - nums.begin()-1};
    }
};
