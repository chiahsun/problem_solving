class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it1 = std::lower_bound(nums.begin(), nums.end(), target);
        auto it2 = std::upper_bound(nums.begin(), nums.end(), target);
        if (it1 == it2) return std::vector<int>{-1, -1};
        
        int begin = it1 - nums.begin();
        return std::vector<int>{begin, begin + it2 - it1-1};
    }
};
