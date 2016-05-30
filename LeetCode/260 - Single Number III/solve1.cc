class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        std::set<int> s;
        for (int x : nums)
            if (s.count(x))
                s.erase(x);
            else
                s.insert(x);
        std::vector<int> v(s.begin(), s.end());
        while (v.size() < 2) v.push_back(0);
        
        return v;
    }
};
