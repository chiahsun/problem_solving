class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() <= 1 or k <= 0) return false;
        std::unordered_map<int, int> last;
        for (int i = 0; i < nums.size(); ++i) {
            int cur = nums[i];
            if (last.find(cur) == last.end()) last.insert(std::make_pair(cur, i));
            else {
                if (i - last[cur] <= k) return true;
                last[cur] = i;
            }
        }
        return false;
    }
};
