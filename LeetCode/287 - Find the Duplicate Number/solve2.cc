class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::set<int> s;
        for (int val : nums) {
            if (s.count(val)) return val;
            s.insert(val);
        }
        return -1;
    }
};
