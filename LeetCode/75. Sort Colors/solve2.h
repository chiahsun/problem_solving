class Solution {
public:
  void sortColors(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1, i = 0;
        while (lo < hi && i < hi) {
            while (lo < nums.size() && nums[lo] == 0) ++lo;
            while (hi > 0 && nums[hi] == 2) --hi;
            if (lo >= hi) break;
            if (i < lo) { i = lo+1; }
            if (nums[lo] == 2 || nums[hi] == 0) std::swap(nums[lo], nums[hi]);
            else {
                while (i < hi && nums[i] == 1) ++i;
                if (i < hi) {
                    if (nums[i] == 0) std::swap(nums[lo], nums[i]);
                    else              std::swap(nums[hi], nums[i]);
                    ++i;
                }
            }
        }
    }
};
