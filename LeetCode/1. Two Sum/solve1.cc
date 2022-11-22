class Solution {
public:
    struct PairFirstLess {
        bool operator () (const std::pair<int, int> & x, const std::pair<int, int> & y) const
          { return x.first < y.first; }
    };
    
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<std::pair<int, int> > prs;
        for (int i = 0; i < nums.size(); ++i)
            prs.push_back(std::make_pair(nums[i], i));
        std::sort(prs.begin(), prs.end());
        
        for (int i = 0; i < prs.size(); ++i) {
            std::pair<int, int> x = prs[i];
            std::pair<int, int> y = std::make_pair(target-x.first, 0);
            auto it = prs.end();
            if (y.first >= x.first)
                it = std::lower_bound(prs.begin()+i+1, prs.end(), y, PairFirstLess());
            else 
                it = std::lower_bound(prs.begin(), prs.begin()+i, y, PairFirstLess());
            
            if (it->first + x.first == target) {// may no such element in the lower interval 
                if (x.second <= it->second) return {x.second, it->second};
                else                        return {it->second, x.second};
            }
        }
        return {};
    }
};
