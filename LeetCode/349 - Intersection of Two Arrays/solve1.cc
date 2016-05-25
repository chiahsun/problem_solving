class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        
        std::vector<int> res;
        for (int i = 0, k = 0; i < nums1.size() and k < nums2.size(); ) {
            if (nums1[i] == nums2[k]) {
                if (res.empty() or res.back() != nums1[i])
                    res.push_back(nums1[i]);
                ++i, ++k;
            } else if (nums1[i] < nums2[k]) {
                ++i;
            } else {
                ++k;
            }
        }
        
        return res;
    }
};
