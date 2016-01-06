class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> m;
        for (const auto & x : nums) {
            if (not m.count(x))
                m.insert(std::make_pair(x, 0));
            ++m[x];
        }
        int max = m.begin()->first, max_cnt = m.begin()->second;
        for (const auto & pr : m) {
            if (pr.second > max_cnt) {
                max = pr.first;
                max_cnt = pr.second;
            }
        }
        return max;
    }
};
